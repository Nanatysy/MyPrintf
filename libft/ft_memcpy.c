#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*tmp;
	const unsigned char	*tsrc;

	if (!src && !dst)
		return (NULL);
	tmp = dst;
	tsrc = src;
	i = 0;
	while (i < n)
	{
		tmp[i] = tsrc[i];
		i++;
	}
	return (dst);
}
