#include "libftprintf.h"

size_t	ft_pow(int base, int a)
{
	long int	res;

	res = 1;
	while (a > 0)
	{
		res *= base;
		a--;
	}
	return (res);
}

void	ft_base_conver(size_t a, int flag)
{
	char			res[17];
	int				rank;
	int				i;
	int				tmp;
	size_t			pow;

	rank = ft_count_rank(a, 16) - 1;
	i = 0;
	while (rank >= 0)
	{
		pow = ft_pow(16, rank);
		tmp = a / pow;
		if (tmp > 9)
			res[i] = 'a' + tmp - 10 + flag;
		else
			res[i] = tmp + '0';
		a %= pow;
		rank--;
		i++;
	}
	res[i] = '\0';
	write(1, res, i);
}
