#include "minunit.h"
#include "../srcs/get_next_line.h"

MU_TEST_SUITE(test)
{
	//ARRANGE
	int			fd						= open("./files/fill_list_nl", O_RDONLY);
	t_list		*result_lst 			= ft_lstnew(NULL, 0);
	static char	r_buffer[BUFFER_SIZE];

	//ACT
	if (fd == -1)
		return ;

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
	MU_RUN_TEST(test);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
