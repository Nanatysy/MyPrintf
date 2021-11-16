#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	res = (void*)malloc(count * size);
	if (!res)
		return (NULL);
	ft_bzero(res, count * size);
	return (res);
}
