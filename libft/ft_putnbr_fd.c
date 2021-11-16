#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			tmp[11];
	int				i;
	int				flag;
	unsigned int	new;

	i = 0;
	flag = (n < 0) ? 1 : 0;
	new = (flag == 1) ? -n : n;
	if (new)
	{
		while (new)
		{
			tmp[i++] = (char)((new % 10) + '0');
			new /= 10;
		}
		if (flag == 1)
			tmp[i++] = '-';
		while (i > 0)
			write(fd, &tmp[--i], 1);
	}
	else
		write(fd, "0", 1);
}
