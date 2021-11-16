#include "libftprintf.h"

void	ft_write_spase(int count, int stop)
{
	while (count > stop)
	{
		write(1, " ", 1);
		count--;
	}
}

int		ft_print_c(t_info *tmp, va_list *current)
{
	char	c;
	int		res;

	res = (tmp->width > 1) ? tmp->width : 1;
	c = va_arg(*current, int);
	if (tmp->flag == 'x' || tmp->flag == '0')
		ft_write_spase(res, 1);
	write(1, &c, 1);
	if (tmp->flag == '-')
		ft_write_spase(res, 1);
	return (res);
}

int		ft_print_s(t_info *tmp, va_list *current)
{
	char	*s;
	int		res;
	int		i;
	int		count;

	s = va_arg(*current, char*);
	if (!s)
		s = "(null)";
	count = ft_strlen(s);
	res = (tmp->precision > count || tmp->precision == -1) ? \
	count : tmp->precision;
	count = res;
	res = (res > tmp->width) ? res : tmp->width;
	if (tmp->flag == 'x' || tmp->flag == '0')
		ft_write_spase(res, count);
	i = 0;
	while (i < count)
	{
		write(1, &s[i], 1);
		i++;
	}
	if (tmp->flag == '-' || tmp->flag == '2')
		ft_write_spase(res, count);
	return (res);
}

int		ft_print_p(t_info *tmp, va_list *current)
{
	size_t	p;
	int		res;
	int		count;
	int		i;

	p = va_arg(*current, size_t);
	count = ft_count_rank(p, 16) + 2;
	if (tmp->precision == 0 && p == 0)
		count = 2;
	i = (tmp->precision > count - 2) ? tmp->precision + 2 : count;
	res = (tmp->width > i) ? tmp->width : i;
	if (tmp->flag == 'x')
		ft_write_spase(res, i);
	write(1, "0x", 2);
	while (tmp->precision > count - 2)
	{
		tmp->precision--;
		write(1, "0", 1);
	}
	if (tmp->precision != 0 || p != 0)
		ft_base_conver(p, 0);
	if (tmp->flag == '-' || tmp->flag == '2')
		ft_write_spase(res, i);
	return (res);
}

int		ft_print_per(t_info *tmp)
{
	int		res;

	res = (tmp->width > 1) ? tmp->width : 1;
	if (tmp->flag == '2')
		tmp->flag = '-';
	if (tmp->flag != '-')
	{
		if (tmp->flag == ' ')
			tmp->flag = '0';
		ft_write_extra(1, res, tmp->flag);
	}
	write(1, &tmp->type, 1);
	if (tmp->flag == '-')
		ft_write_spase(res, 1);
	return (res);
}
