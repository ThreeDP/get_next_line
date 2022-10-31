#include "minunit.h"
#include "../srcs/get_next_line.h"

MU_TEST_SUITE(test_check)
{
	//ARRANGE
	int		fd;
	char	*read_f;
	char	expected1[] = "\n";
	char	*expected2 = NULL;

	//ACT
	fd = open("files/nl", O_RDONLY);
	if (fd == -1)
		return ;

	//ASSERT
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
	MU_RUN_TEST(test_check);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
