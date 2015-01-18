#include <project.h>

static void simple_test(t_test *test)
{
	char	control[10];
	char	subject[] = "123456789";

	bzero(control, 10);
	ft_bzero(subject, 10);
	mt_assert(memcmp(control, subject, 10) == 0);
	subject[0] = 'a';
	ft_bzero(subject, 0);
	mt_assert(subject[0] == 'a');
}

static void test_only_bzero_first_x_chars(t_test *test)
{
	char	control[] = "123456789";
	char	subject[] = "123456789";

	bzero(control, 3);
	ft_bzero(subject, 3);
	mt_assert(memcmp(subject, control, 10) == 0);
}

static void test_zero_byte(t_test *test)
{
	char	control[] = "123456789";
	char	subject[] = "123456789";

	bzero(control, 0);
	ft_bzero(subject, 0);
	mt_assert(memcmp(subject, control, 10) == 0);
}

static void test_large_value(t_test *test)
{
	int		test_size = 1 * 1000 * 1000;
	char	control[test_size];
	char	subject[test_size];

	memset(subject, 'a', test_size);
	memset(control, 'a', test_size);
	bzero(control, test_size);
	ft_bzero(subject, test_size);
	mt_assert(memcmp(subject, control, test_size) == 0);
}

void	suite_00_part1_ft_bzero(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, test_only_bzero_first_x_chars);
	SUITE_ADD_TEST(suite, test_zero_byte);
	SUITE_ADD_TEST(suite, test_large_value);
}
