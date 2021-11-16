#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_info
{
	char		flag;
	int			width;
	int			precision;
	char		type;
}				t_info;

size_t			ft_pow(int base, int a);
void			ft_write_spase(int count, int stop);
void			ft_write_extra(int count, int width, char flag);
void			ft_work_with_flag(const char *s, int *i, t_info **new);
void			ft_work_with_width(const char *s, int *i, t_info **new, \
va_list *c);
void			ft_work_with_prec(const char *s, int *i, t_info **new, \
va_list *c);
void			ft_base_conver(size_t a, int flag);
void			ft_print_nd(long int arg, int count, t_info *tmp);
void			ft_putlnb(long int n);
int				ft_fill_the_info(const char *s, t_info **new, \
va_list *current, int *i);
int				ft_printf(const char *str, ...);
int				ft_its_percent(int *i, const char *s, va_list *tmp);
int				ft_chose_func(t_info *cur, va_list *tmp);
int				ft_count_rank(size_t a, int base);
int				ft_count_all(int *i, int *count, long int arg, t_info *tmp);
int				ft_print_d(t_info *tmp, va_list *current);
int				ft_print_u(t_info *tmp, va_list *current);
int				ft_print_x(t_info *tmp, va_list *current);
int				ft_print_c(t_info *tmp, va_list *current);
int				ft_print_s(t_info *tmp, va_list *current);
int				ft_print_p(t_info *tmp, va_list *current);
int				ft_print_per(t_info *tmp);

#endif
