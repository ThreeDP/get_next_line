#include "minunit.h"
#include "../srcs/get_next_line.h"

MU_TEST_SUITE(test)
{
	//ARRANGE
    int			fd						= open("./files/43_with_nl", O_RDONLY);
    t_list		*lst	        	    = ft_lstnew(NULL, 0);
    size_t      string_size;
	static char	buffer[BUFFER_SIZE];
    char        *expected_buffer1       = "7";
//    char        *expected_buffer2       = "\0";
//    char        *expected_buffer3       = "\0";

    //ACT
    if (fd == -1)
		return ;

	//ASSERT
    /* 1 */
    check_static(fd, buffer, &lst);
    string_size = make_pieces(fd, buffer, &lst);
    mu_assert_string_eq("012345678901234567890123456789012345678901", lst-> content);
    lst = lst-> next;
    mu_assert_string_eq("\n", lst-> content);
    mu_assert_int_eq(43, string_size);
    mu_assert_string_eq(expected_buffer1, buffer);
    ft_lstclear(&lst, free);
    /* 2 */
    lst	        	    = ft_lstnew(NULL, 0);
    check_static(fd, buffer, &lst);
    string_size = make_pieces(fd, buffer, &lst);
    mu_assert_string_eq("7", lst-> content);
    mu_assert_int_eq(1, string_size);
//    mu_assert_string_eq(expected_buffer2, buffer);
    ft_lstclear(&lst, free);
    /* 3 */
    lst	        	    = ft_lstnew(NULL, 0);
    check_static(fd, buffer, &lst);
    string_size = make_pieces(fd, buffer, &lst);
    mu_assert_string_eq(NULL, lst-> content);
    mu_assert_int_eq(0, string_size);
//    mu_assert_string_eq(expected_buffer3, buffer);
    ft_lstclear(&lst, free);
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