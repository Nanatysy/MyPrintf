#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	l;

	i = 0;
	if (!s)
		return (NULL);
	l = ft_strlen(s) - start + 1;
	if (start > ft_strlen(s))
		l = 1;
	if (l < len)
		res = (char*)malloc(l);
	else
		res = (char*)malloc(len + 1);
	if (res)
	{
		while (i < len && s[start] != '\0' && l != 1)
			res[i++] = s[start++];
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
