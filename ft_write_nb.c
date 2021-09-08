/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <dwillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:59:28 by dwillett          #+#    #+#             */
/*   Updated: 2020/11/24 14:45:58 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_count_rank(size_t a, int base)
{
	int	count;

	count = 0;
	if (a == 0)
		return (1);
	while (a != 0)
	{
		a /= base;
		count++;
	}
	return (count);
}

void	ft_write_extra(int count, int width, char flag)
{
	if (flag == 'x' || flag == '-' || flag == '2')
		flag = ' ';
	while (width > count)
	{
		write(1, &flag, 1);
		width--;
	}
}

int		ft_print_d(t_info *tmp, va_list *current)
{
	long int	arg;
	int			i;
	int			res;
	int			count;

	arg = va_arg(*current, int);
	res = ft_count_all(&i, &count, arg, tmp);
	if (arg >= 0)
	{
		if (tmp->flag != '-' && tmp->flag != '2')
			ft_write_extra(count, tmp->width, tmp->flag);
		while (tmp->precision > i)
		{
			tmp->precision--;
			write(1, "0", 1);
		}
		if (tmp->precision != 0 || arg != 0)
			ft_putnbr_fd(arg, 1);
		if (tmp->flag == '-' || tmp->flag == '2')
			ft_write_extra(count, tmp->width, tmp->flag);
	}
	else
		ft_print_nd(arg, i, tmp);
	return (res);
}

int		ft_print_u(t_info *tmp, va_list *current)
{
	unsigned int	arg;
	int				count;
	int				res;
	int				i;

	arg = va_arg(*current, unsigned int);
	res = ft_count_all(&i, &count, arg, tmp);
	if (tmp->flag != '-' && tmp->flag != '2')
		ft_write_extra(count, tmp->width, tmp->flag);
	while (tmp->precision > i)
	{
		write(1, "0", 1);
		tmp->precision--;
	}
	if (tmp->precision != 0 || arg != 0)
	{
		if ((arg / 100000) != 0)
			ft_putnbr_fd(arg / 100000, 1);
		ft_putnbr_fd(arg % 100000, 1);
	}
	if (tmp->flag == '-' || tmp->flag == '2')
		ft_write_extra(count, tmp->width, tmp->flag);
	return (res);
}

int		ft_print_x(t_info *tmp, va_list *current)
{
	unsigned int	arg;
	int				count;
	int				i;
	int				res;
	int				flag;

	arg = va_arg(*current, unsigned int);
	i = ft_count_rank(arg, 16);
	res = (i > tmp->precision && (tmp->precision != 0 || arg != 0)) \
	? i : tmp->precision;
	count = res;
	res = (tmp->width > res) ? tmp->width : res;
	if (tmp->flag != '-' && tmp->flag != '2')
		ft_write_extra(count, tmp->width, tmp->flag);
	while (tmp->precision > i)
	{
		write(1, "0", 1);
		tmp->precision--;
	}
	flag = (tmp->type == 'X') ? -32 : 0;
	if (tmp->precision != 0 || arg != 0)
		ft_base_conver(arg, flag);
	if (tmp->flag == '-' || tmp->flag == '2')
		ft_write_extra(count, tmp->width, tmp->flag);
	return (res);
}
