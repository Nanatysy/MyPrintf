/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <dwillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:23:04 by dwillett          #+#    #+#             */
/*   Updated: 2020/11/04 20:13:33 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
