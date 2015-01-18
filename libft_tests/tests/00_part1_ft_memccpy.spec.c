#include <project.h>

static void simple_test(t_test *test)
{
	char *str1 = ft_strdup("xxxxxxx");
	char *str2 = "test";

	mt_assert(ft_memccpy(str1, strdup(str2), 'e', 20) ==
			     memccpy(str1, strdup(str2), 'e', 20));
}

static void simple_not_found(t_test *test)
{
	char *str1 = ft_strdup("xxxx");
	char *str2 = "test";

	mt_assert(ft_memccpy(str1, strdup(str2), 'z', 5) ==
			     memccpy(str1, strdup(str2), 'z', 5));
}

static void unittest(t_test *test)
{
	char	buf1[] = "Ceci est un test.";
	char	buf2[200];
	void	*p1, *p2;

	p1 = memccpy(buf2, buf1, 'i', 10);
	p2 = ft_memccpy(buf2, buf1, 'i', 10);
	mt_assert(p1 == p2);
	mt_assert(ft_memccpy(buf2, buf1, 'k', 5) == 0);
	mt_assert(ft_memccpy(buf2, buf1, 0, 0) == memccpy(buf2, buf1, 0, 0));
	mt_assert(ft_memccpy(buf2, buf1, 0, sizeof(buf1)) == memccpy(buf2, buf1, 0, sizeof(buf1)));
	mt_assert(ft_memccpy(buf2, buf1, 'C', 10) == buf2 + 1);
}

static void test_unsigned_chars(t_test *test)
{
	char dest[] = "abcdefghijklmnopqrstuvwxyz";

	mt_assert(ft_memccpy(dest, strdup("test\200string"), '\200', 12) ==
		memccpy(dest, strdup("test\200string"), '\200', 12));
}

void	suite_00_part1_ft_memccpy(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, simple_not_found);
	SUITE_ADD_TEST(suite, unittest);
	SUITE_ADD_TEST(suite, test_unsigned_chars);
}
