#include "minunit.h"
#include "../srcs/get_next_line.h"

MU_TEST_SUITE(passing_the_file_fill_list_nl_with_static_NULL_execute_read_function)
{
	//ARRANGE
	int			fd						= open("./files/fill_list_nl", O_RDONLY);
	t_list		*result_lst 			= ft_lstnew(NULL, 0);
	static char	r_buffer[BUFFER_SIZE];
    char        *expected_buffer        = "O";
    size_t      expected_buf_read_size  = BUFFER_SIZE;

	//ACT
	if (fd == -1)
		return ;
    check_static(fd, r_buffer, &result_lst);

	//ASSERT
    mu_assert_int_eq(expected_buf_read_size, result_lst-> buf_read);
    mu_assert_string_eq(expected_buffer, r_buffer);
	ft_lstclear(&result_lst, free);
	close(fd);
}

MU_TEST_SUITE(test)
{
	//ARRANGE
	int			fd						= open("./files/41_with_nl", O_RDONLY);
	t_list		*result_lst 			= ft_lstnew(NULL, 0);
	static char	r_buffer[BUFFER_SIZE];
    char        *expected_buffer1       = "0";
	char		*expected_buffer2		= "7";
    size_t      expected_buf_read_size  = BUFFER_SIZE;

	//ACT
	if (fd == -1)
		return ;
    check_static(fd, r_buffer, &result_lst);

	//ASSERT
    mu_assert_int_eq(expected_buf_read_size, result_lst-> buf_read);
    mu_assert_string_eq(expected_buffer1, r_buffer);
	fill_list(fd, r_buffer, &result_lst);
	ft_lstclear(&result_lst, free);

	result_lst 			= ft_lstnew(NULL, 0);
	check_static(fd, r_buffer, &result_lst);

	//ASSERT
	mu_assert_string_eq(expected_buffer2, r_buffer);
    mu_assert_int_eq(expected_buf_read_size, result_lst-> buf_read);
	ft_lstclear(&result_lst, free);
	close(fd);
}

MU_TEST_SUITE(test_suite)
{	
	MU_RUN_TEST(test);
	MU_RUN_TEST(passing_the_file_fill_list_nl_with_static_NULL_execute_read_function);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
