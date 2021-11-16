#include "libftprintf.h"

t_info	*ft_new_info(void)
{
	t_info	*new;

	if (!(new = (t_info*)malloc(sizeof(t_info))))
		return (NULL);
	new->flag = 'x';
	new->width = 0;
	new->precision = -1;
	return (new);
}

void	ft_work_with_flag(const char *s, int *i, t_info **new)
{
	t_info *tmp;

	tmp = *new;
	while (s[*i] == '-' || s[*i] == '0')
	{
		if (s[*i] == '-')
		{
			if (tmp->flag == 'x')
				tmp->flag = '-';
			else if (tmp->flag == '0')
				tmp->flag = '2';
		}
		else
		{
			if (tmp->flag == 'x')
				tmp->flag = '0';
			else if (tmp->flag == '-')
				tmp->flag = '2';
		}
		*i = *i + 1;
	}
}

void	ft_work_with_width(const char *s, int *i, t_info **new, va_list *c)
{
	t_info *tmp;

	tmp = *new;
	if (s[*i] == '*')
	{
		tmp->width = va_arg(*c, int);
		if (tmp->width < 0)
		{
			tmp->flag = '-';
			tmp->width = -tmp->width;
		}
		*i = *i + 1;
	}
	else
	{
		tmp->width = ft_atoi(s + *i);
		while (ft_isdigit(s[*i]))
			*i = *i + 1;
	}
}

void	ft_work_with_prec(const char *s, int *i, t_info **new, va_list *c)
{
	t_info *tmp;

	tmp = *new;
	*i = *i + 1;
	if (s[*i] == '*')
	{
		tmp->precision = va_arg(*c, int);
		if (tmp->precision < 0)
			tmp->precision = -1;
		*i = *i + 1;
	}
	else if (ft_isdigit(s[*i]))
	{
		tmp->precision = ft_atoi(s + *i);
		while (ft_isdigit(s[*i]))
			*i = *i + 1;
	}
	else
		tmp->precision = 0;
	if (tmp->flag == '0' && tmp->precision != -1)
		tmp->flag = 'x';
}

int		ft_fill_the_info(const char *s, t_info **new, va_list *current, int *i)
{
	t_info	*tmp;

	if (!(tmp = ft_new_info()))
		return (0);
	*new = tmp;
	if (s[*i] == '%')
	{
		*i = *i + 1;
		if (s[*i] == '-' || s[*i] == '0')
			ft_work_with_flag(s, i, new);
		if (s[*i] == '*' || ft_isdigit(s[*i]))
			ft_work_with_width(s, i, new, current);
		if (s[*i] == '.')
			ft_work_with_prec(s, i, new, current);
		tmp->type = s[*i];
		if (tmp->type == 'i')
			tmp->type = 'd';
		*i = *i + 1;
		return (1);
	}
	return (0);
}
