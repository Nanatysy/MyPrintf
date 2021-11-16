#include "libftprintf.h"

int		ft_count_all(int *i, int *count, long int arg, t_info *tmp)
{
	int	res;
	int	flag;

	flag = (arg < 0) ? 1 : 0;
	*i = (arg < 0) ? ft_count_rank(-arg, 10) : ft_count_rank(arg, 10);
	res = (*i > tmp->precision && (tmp->precision != 0 || arg != 0)) \
	? *i : tmp->precision;
	*count = res + flag;
	res = (tmp->width > *count) ? tmp->width : *count;
	return (res);
}

void	ft_putlnb(long int n)
{
	int		p;
	int		rank;
	char	c;

	rank = ft_count_rank(n, 10) - 1;
	while (rank >= 0)
	{
		p = ft_pow(10, rank);
		c = n / p + '0';
		write(1, &c, 1);
		n = n % p;
		rank--;
	}
}

void	ft_print_nd(long int arg, int count, t_info *tmp)
{
	int	f;
	int	res;

	f = 0;
	res = (count > tmp->precision) ? count + 1 : tmp->precision + 1;
	if (tmp->flag == '0' || tmp->flag == 'x')
	{
		if (tmp->flag == '0')
		{
			f = 1;
			write(1, "-", 1);
		}
		ft_write_extra(res, tmp->width, tmp->flag);
	}
	if (f == 0)
		write(1, "-", 1);
	while (tmp->precision-- > count)
		write(1, "0", 1);
	ft_putlnb(-arg);
	if (tmp->flag == '-' || tmp->flag == '2')
		ft_write_extra(res, tmp->width, tmp->flag);
}
