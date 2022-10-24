/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:50:44 by dapaulin          #+#    #+#             */
/*   Updated: 2022/10/09 19:50:33 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "../srcs/get_next_line.h"

MU_TEST_SUITE(passing_a_file_with_TU_string_with_a_BUFFERSIZE_5_should_be_TU)
{
	//ARRANGE
	int		fd;
	char	*read_f;
	char	expected[] = "TU\n";
	
	//ACT
	fd = open("files/42", O_RDONLY);
	if (fd == -1)
		return ;
	read_f = get_next_line(fd);

	//ASSERT
	mu_assert_string_eq(expected, read_f);
	free(read_f);
	close(fd);
}

MU_TEST_SUITE(test_suite)
{	
	MU_RUN_TEST(passing_a_file_with_TU_string_with_a_BUFFERSIZE_5_should_be_TU);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
