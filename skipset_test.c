#include "flags.h"
#include <stdio.h>
#include <assert.h>
#include "skipset.h"
void	Test1()
{
	char *str = "---3222";
	int skip_count;

	t_flag flg;

	skip_count = skipset_minus(str, &flg);
	printf("Begin Test 1 skipset_minus test\n");
	assert(skip_count == 7);
	assert(flg.width.is_left == 1);
	assert(flg.width.width == 3222);
	printf("Test 1 OK\n");
}

void	Test2()
{
	char *str = "00043---";
	int skip_count;

	t_flag flg;
	skip_count = skipset_zero(str, &flg);
	printf("Test 2 skipset_zero test\n");
	assert(skip_count == 5);
	assert(flg.precision.length == 43);
	printf("Test 2 OK\n");
}

void	Test3()
{
	char *str = ".43";
	int skip_count;

	t_flag flg;
	skip_count = skipset_dot(str, &flg);
	printf("Test 3 skipset_dot test\n");
	assert(skip_count == 3);
	assert(flg.precision.length == 43);
	printf("Test 3 OK\n");
}

void	Test4()
{
	char *str = "23.2c";
	t_flag flg;
	int skip_count = skipset(str, &flg);
	printf("Test 4 skipset main test\n");
	assert(skip_count == 4);
	assert(flg.precision.length == 2);
	assert(flg.width.is_left == 0);
	assert(flg.width.width == 23);
	printf("Test 4 OK\n");
}

int	main()
{
	Test1();
	Test2();
	Test3();
	Test4();	
	return (0);
}
