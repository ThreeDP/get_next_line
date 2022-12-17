#include "minunit.h"
#include "../srcs/get_next_line.h"

MU_TEST_SUITE(test)
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
    mu_assert_int_eq(ft_strlen(expected_str1), ft_strlen(str1));
    mu_assert_int_eq(ft_strlen(expected_str2), ft_strlen(str2));
    mu_assert_string_eq(expected_str1, str1);
    mu_assert_string_eq(expected_str2, str2);
    if (str1)
        free(str1);
    if (str2)
        free(str2);
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