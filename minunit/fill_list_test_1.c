/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list_test_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:50:44 by dapaulin          #+#    #+#             */
/*   Updated: 2022/10/30 17:06:10 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "../srcs/get_next_line.h"

MU_TEST_SUITE(passing_the_file_fill_list_nl_should_be_size_line_5_with_5_content_in_the_list)
{
	//ARRANGE
	int			fd						= open("./files/fill_list_nl", O_RDONLY);
	int			i 						= 0;
	size_t		result_line_size;
	t_list		*result_lst 			= ft_lstnew(NULL, 0);
	t_list		*reset					= result_lst;
	static char	r_buffer[BUFFER_SIZE];
	size_t		expected_line_size 		= 5;
	char		*expected1	 			= "O";
	char		*expected2	 			= "n";
	char		*expected3	 			= "e";
	char		*expected4	 			= "!";
	char		*expected5	 			= "\n";
	char		**expected = (char **) calloc(5 + 1, sizeof(char *));
	char		expected_buffer[] 		= "\n";

	//ACT
	if (fd == -1)
		return ;
	if (!expected)
		return ;
	expected[0] = expected1;
	expected[1] = expected2;
	expected[2] = expected3;
	expected[3] = expected4;
	expected[4] = expected5;
	result_lst -> buf_read = read(fd, r_buffer, BUFFER_SIZE);
	result_line_size = fill_list(fd, r_buffer, &result_lst);

	//ASSERT
	result_lst = reset;
	mu_assert_int_eq(expected_line_size, result_line_size);
	while (result_lst)
	{
		mu_assert_string_eq(expected[i++], result_lst -> content);
		result_lst = result_lst -> next;
	}
	mu_assert_string_eq(expected_buffer, r_buffer);
	ft_lstclear(&reset, free);
	free(expected);
	close(fd);
}

MU_TEST_SUITE(passing_the_file_71_no_nl_should_be_size_line_71_with_71_content_in_the_list)
{
	//ARRANGE
	int		fd				= open("./files/71_no_nl", O_RDONLY);
	int		i 				= 0;
	char		*string				= (char *) calloc(BUFFER_SIZE + 1, sizeof(char));
	size_t		result_line_size;
	t_list		*result_lst 			= ft_lstnew(NULL, 0);
	t_list		*reset					= result_lst;
	static char	r_buffer[BUFFER_SIZE];
	size_t		expected_line_size 		= 71;
	const char	*expected	 		= "Para olhos tortos, a realidade pode ter um rosto desvirtuado - Gandalf.";
	char		expected_buffer[] 		= "\0";

	//ACT
	if (fd == -1)
		return ;
	result_lst -> buf_read = read(fd, r_buffer, BUFFER_SIZE);
	result_line_size = fill_list(fd, r_buffer, &result_lst);

	//ASSERT
	result_lst = reset;
	mu_assert_int_eq(expected_line_size, result_line_size);
	while (result_lst)
	{
		ft_strlcpy(string, &expected[i++], BUFFER_SIZE + 1);
		mu_assert_string_eq(string, result_lst -> content);
		result_lst = result_lst -> next;
	}
	mu_assert_string_eq(expected_buffer, r_buffer);
	ft_lstclear(&reset, free);
	close(fd);
}

MU_TEST_SUITE(test_suite)
{	
	MU_RUN_TEST(passing_the_file_fill_list_nl_should_be_size_line_5_with_5_content_in_the_list);
	MU_RUN_TEST(passing_the_file_71_no_nl_should_be_size_line_71_with_71_content_in_the_list);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
