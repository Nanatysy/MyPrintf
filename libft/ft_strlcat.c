#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	if (dstsize != 0 && i <= dstsize)
	{
		while (i < dstsize - 1 && src[j] != '\0')
			dst[i++] = src[j++];
		dst[i] = '\0';
		while (src[j++] != '\0')
			i++;
		return (i);
	}
	return (ft_strlen(src) + dstsize);
}
