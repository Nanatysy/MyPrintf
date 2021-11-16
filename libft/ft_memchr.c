#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*tsrc;

	tsrc = s;
	i = 0;
	while (i < n)
	{
		if (tsrc[i] == (unsigned char)c)
			return ((void*)s + i);
		i++;
	}
	return (NULL);
}
