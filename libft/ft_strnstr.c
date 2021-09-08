/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <dwillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 10:14:39 by dwillett          #+#    #+#             */
/*   Updated: 2020/11/09 15:41:52 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle && needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		while (haystack[i] == needle[j] && i < len && haystack[i] != '\0')
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char*)(haystack + i - j));
		i = i + 1 - j;
		j = 0;
	}
	return (NULL);
}
