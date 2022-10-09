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

MU_TEST_SUITE(test_check) {
	//ARRANGE
	int		fd;
	char	*read;
	char	expected[] = "TU";
	
	//ACT
	fd = open("42", O_RDONLY);
	read = get_next_line(fd);

	//ASSERT
	mu_assert_string_eq(expected, read);
}

MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(test_check);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}