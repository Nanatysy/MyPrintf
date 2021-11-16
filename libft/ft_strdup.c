#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;

	i = 0;
	res = (char*)malloc(ft_strlen(s1) + 1);
	if (res)
	{
		while (s1[i] != '\0')
		{
			res[i] = s1[i];
			i++;
		}
		res[i] = s1[i];
		return (res);
	}
	return (NULL);
}
