#include "skipset.h"

static int digit_count(int n)
{
	int i;

	i = 0;
	if (n == 0)
		i++;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	skipset_minus(char *s, t_flag *flg)
{
	int i;

	i = 0;
	flg->width.is_left = 0;
	while (s[i] == '-')
	{
		flg->width.is_left = 1;
		i++;
	}
	if (s[i] && s[i] != '0')
		flg->width.width = ft_atoi(&s[i]);
	i += digit_count(flg->width.width);
	return (i);
}


int	skipset_zero(char *s, t_flag *flg)
{
	int i;
	flg->precision.length = -1;
	i = 0;
	while (s[i] == '0')
	{
		i++;
		flg->precision.length = 1;
	}
	if (flg->precision.length != -1)
		flg->precision.length = ft_atoi(&s[0]);
	i += digit_count(flg->precision.length);
	return (i);
}

int	skipset_dot(char *s, t_flag *flg)
{
	int i;

	i = 0;
	while (s[i] == '.')
		i++;
	if (s[i] && s[i] != '0')
		flg->precision.length = ft_atoi(&s[i]);
	i += digit_count(flg->precision.length);
	return (i);

}

int	skipset(char *s, t_flag *flg)
{
	int i;

	i = skipset_zero(s, flg);
	i += skipset_minus(&s[i], flg);
	i += skipset_dot(&s[i], flg);
	return (i);
}
