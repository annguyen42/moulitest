#include <project.h>

#define mt_test_memchr(test_name, str, c, size) \
	static void test_## test_name(t_test *test) \
	{ \
		mt_assert(ft_memchr(str, c, size) == memchr(str, c, size)); \
	}

mt_test_memchr(00, "abcdef", 'a', 5);
mt_test_memchr(01, "abcdef", 'c', 5);
mt_test_memchr(02, "abcdef", '\0', 7);
mt_test_memchr(03, "abcdef", 'z', 6);
mt_test_memchr(04, "abcdef", 999, 6);

static void barbarian_test(t_test *test)
{
	/* Barbarian test from Qperez !! */
	char			ctab[11];
	int				itab[11];
	unsigned long	ltab[11];
	size_t			j;
	int				i;

	i = -300;
	ft_memchr(NULL, 0, 0);
	while (i < 300)
	{
		j = 0;
		while (j < 11)
		{
			ctab[j] = (char)rand();
			itab[j] = rand();
			ltab[j] = (unsigned long)rand() * 10000;
			j++;
		}
		if ((memchr(ctab, i, sizeof(ctab)) != ft_memchr(ctab, i, sizeof(ctab)))
			|| ((memchr(itab, i, sizeof(itab)) != ft_memchr(itab, i, sizeof(itab))))
			|| (memchr(ltab, i, sizeof(ltab)) != ft_memchr(ltab, i, sizeof(ltab))))
		{
			mt_assert(!"Unsigned char problem?");
			break;
		}
		++i;
	}
/*
	ft_memchr(NULL, 0, 0);
	ft_memchr(NULL, 0, 10);
	ft_memchr(NULL, -10, 10);
*/
}

static void large_size(t_test *test)
{
	int size = 1 * 1000 * 1000;
	char str[size];

	bzero(str, size);
	str[size - 1] = 'z';

	mt_assert(ft_memchr(str, 'z', size) == memchr(str, 'z', size));
}

void	suite_00_part1_ft_memchr(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_00);
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
	SUITE_ADD_TEST(suite, test_03);
	SUITE_ADD_TEST(suite, test_04);
	SUITE_ADD_TEST(suite, barbarian_test);
	SUITE_ADD_TEST(suite, large_size);
}
