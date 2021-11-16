#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	int			tmp;

	i = 0;
	tmp = -1;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			tmp = i;
		i++;
	}
	if (tmp == -1)
	{
		if ((char)c == '\0')
			return ((char*)(s + i));
		return (NULL);
	}
	return ((char*)(s + tmp));
}
