/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <dwillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:07:25 by dwillett          #+#    #+#             */
/*   Updated: 2020/11/23 16:47:08 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_chose_func(t_info *cur, va_list *tmp)
{
	if (cur->type == 'd')
		return (ft_print_d(cur, tmp));
	else if (cur->type == 'u')
		return (ft_print_u(cur, tmp));
	else if (cur->type == 'x' || cur->type == 'X')
		return (ft_print_x(cur, tmp));
	else if (cur->type == 'c')
		return (ft_print_c(cur, tmp));
	else if (cur->type == 's')
		return (ft_print_s(cur, tmp));
	else if (cur->type == '%')
		return (ft_print_per(cur));
	else if (cur->type == 'p')
		return (ft_print_p(cur, tmp));
	else
		return (-1);
}

int	ft_its_percent(int *i, const char *s, va_list *tmp)
{
	t_info	*cur;
	int		res;

	if (!(ft_fill_the_info(s, &cur, tmp, i)))
	{
		va_end(*tmp);
		return (-1);
	}
	res = ft_chose_func(cur, tmp);
	if (res == -1)
	{
		free(cur);
		va_end(*tmp);
		return (-1);
	}
	free(cur);
	return (res);
}

int	ft_printf(const char *str, ...)
{
	va_list tmp;
	int		i;
	int		t;
	int		res;

	i = 0;
	res = 0;
	va_start(tmp, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if ((t = ft_its_percent(&i, str, &tmp)) == -1)
				return (-1);
			res += t;
		}
		else
		{
			write(1, &str[i++], 1);
			res++;
		}
	}
	va_end(tmp);
	return (res);
}
