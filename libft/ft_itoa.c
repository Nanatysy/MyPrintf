#include "libft.h"

static int	ft_count(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char			*res;
	unsigned int	new;
	int				flag;
	int				i;

	flag = (n < 0) ? 1 : 0;
	new = (flag == 1) ? -n : n;
	res = (char*)malloc(ft_count(new) + flag + 1);
	if (res)
	{
		i = ft_count(new) + flag;
		res[i--] = '\0';
		if (new == 0)
			res[i] = '0';
		while (new)
		{
			res[i--] = (char)(new % 10 + '0');
			new /= 10;
		}
		if (flag)
			res[i] = '-';
		return (res);
	}
	return (NULL);
}
