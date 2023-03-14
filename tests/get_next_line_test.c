#include "minunit-42/minunit.h"
#include "../srcs/get_next_line.h"

MU_TEST_SUITE(test_pass_a_file_with_one_line_with_42_char_and_no_new_line)
{
	//ARRANGE
    int			fd						= open("./files/42_no_nl", O_RDONLY);
    char        *str1;
    char        *expected_str1          = "012345678901234567890123456789012345678901";

    //ACT
    str1 = get_next_line(fd);

    //ASSERT
    mu_assert_int_eq(g_ft_strlen(expected_str1), g_ft_strlen(str1));
    mu_assert_string_eq(expected_str1, str1);
    if (str1)
        free(str1);
}

MU_TEST_SUITE(test_pass_a_file_with_one_line_with_42_char_more_a_new_line_and_other_line_with_one_char)
{
	//ARRANGE
    int			fd						= open("./files/43_with_nl", O_RDONLY);
    char        *str1;
    char        *str2;
    char        *expected_str1          = "012345678901234567890123456789012345678901\n";
    char        *expected_str2          = "7";

    //ACT
    str1 = get_next_line(fd);
    str2 = get_next_line(fd);

    //ASSERT
    mu_assert_int_eq(g_ft_strlen(expected_str1), g_ft_strlen(str1));
    mu_assert_string_eq(expected_str1, str1);
    mu_assert_int_eq(g_ft_strlen(expected_str2), g_ft_strlen(str2));
    mu_assert_string_eq(expected_str2, str2);
    if (str1)
        free(str1);
    if (str2)
        free(str2);
}

MU_TEST_SUITE(test_suite)
{	
    MU_RUN_TEST(test_pass_a_file_with_one_line_with_42_char_and_no_new_line);
    MU_RUN_TEST(test_pass_a_file_with_one_line_with_42_char_more_a_new_line_and_other_line_with_one_char);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}