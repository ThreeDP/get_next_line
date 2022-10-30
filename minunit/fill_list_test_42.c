#include "minunit.h"
#include "../srcs/get_next_line.h"

MU_TEST_SUITE(passing_the_file_fill_list_nl_should_be_size_line_5_with_1_content_in_the_list)
{
	//ARRANGE
	int			fd						= open("./files/fill_list_nl", O_RDONLY);
	size_t		result_line_size;
	t_list		*result_lst 			= ft_lstnew(NULL);
	t_list		*reset					= result_lst;
	static char	r_buffer[BUFFER_SIZE];
	size_t		expected_line_size 		= 5;
	char		*expected	 			= "One!\n";
	char		expected_buffer[] 		= "One!\nRing to rule them all\n";

	//ACT
	if (fd == -1)
		return ;
	read(fd, r_buffer, BUFFER_SIZE);
	result_line_size = fill_list(fd, r_buffer, &result_lst);

	//ASSERT
	result_lst = reset;
	mu_assert_int_eq(expected_line_size, result_line_size);
	mu_assert_string_eq(expected, result_lst -> content);
	mu_assert_string_eq(expected_buffer, r_buffer);
	ft_lstclear(&reset, free);
	close(fd);
}


MU_TEST_SUITE(test_suite)
{	
	MU_RUN_TEST(passing_the_file_fill_list_nl_should_be_size_line_5_with_1_content_in_the_list);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}