#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*res;
	const unsigned char	*tsrc;
	size_t				i;

	res = dst;
	tsrc = src;
	i = 0;
	while (i < n)
	{
		res[i] = tsrc[i];
		if (tsrc[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
