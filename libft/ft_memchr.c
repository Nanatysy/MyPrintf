/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <dwillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 12:14:04 by dwillett          #+#    #+#             */
/*   Updated: 2020/11/01 13:46:41 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
