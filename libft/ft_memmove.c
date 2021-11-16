#include "libft.h"

static int	ft_checkoverlap(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (src + i == dst)
			return (1);
		i++;
	}
	return (0);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*tmp;
	const unsigned char	*tsrc;

	if (!src && !dst)
		return (NULL);
	tmp = dst;
	tsrc = src;
	if (ft_checkoverlap(dst, src, len))
	{
		i = len;
		while (i-- > 0)
			tmp[i] = tsrc[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			tmp[i] = tsrc[i];
			i++;
		}
	}
	return (dst);
}
