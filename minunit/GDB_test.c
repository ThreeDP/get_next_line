/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL_test_1_line_buf_5.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:50:44 by dapaulin          #+#    #+#             */
/*   Updated: 2022/10/30 03:59:08 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "../srcs/get_next_line.h"

MU_TEST_SUITE(test)
{
	//ARRANGE
	int		fd;
	char	*read_f;
	char	expected1[] = "0123456789012345678901234567890123456789\n";
	char	expected2[] = "7";
	
	//ACT
	fd = open("./files/41_with_nl", O_RDONLY);
	if (fd == -1)
		return ;

	read_f = get_next_line(fd);
	mu_assert_string_eq(expected1, read_f);
	free(read_f);
	read_f = get_next_line(fd);
	mu_assert_string_eq(expected2, read_f);
	free(read_f);
	close(fd);
}


MU_TEST_SUITE(test_suite)
{	
	MU_RUN_TEST(test);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
