/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <dwillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:06:52 by dwillett          #+#    #+#             */
/*   Updated: 2020/11/13 13:15:49 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(char *s, char c)
{
	int	i;
	int	count;
	int	word;

	i = 0;
	word = 0;
	count = 1;
	if (s[i] == '\0')
		count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			word = 1;
		if (s[i] == c && word)
		{
			count++;
			word = 0;
		}
		i++;
	}
	return (count);
}

static int		ft_strlen_m(char *s, char c, int start)
{
	int	count;

	count = 0;
	while (s[start] != c && s[start] != '\0')
	{
		count++;
		start++;
	}
	return (count);
}

static char		**ft_clear(char **r, char *t, int j)
{
	if (j >= 0)
	{
		while (j > 0)
			free(r[--j]);
		free(r);
	}
	if (t)
		free(t);
	return (NULL);
}

static char		**ft_mall(char *s, char c)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = (char**)malloc(sizeof(char*) * (ft_count(s, c) + 1));
	if (!res)
		return (ft_clear(res, s, -1));
	while (j < ft_count(s, c))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		res[j] = (char*)malloc(ft_strlen_m(s, c, i) + 1);
		if (!res[j])
			return (ft_clear(res, s, j));
		while (s[i] != c && s[i] != '\0')
			i++;
		j++;
	}
	res[j] = NULL;
	return (res);
}

char			**ft_split(char const *s, char c)
{
	char	**res;
	char	*tmp;
	int		all[4];

	if (!s || !(tmp = ft_strtrim(s, &c)))
		return (NULL);
	if (!(res = ft_mall(tmp, c)))
		return (NULL);
	all[0] = 0;
	all[2] = 0;
	all[3] = ft_count(tmp, c);
	while (all[0] < all[3])
	{
		all[1] = 0;
		while (tmp[all[2]] == c)
			all[2]++;
		while (tmp[all[2]] != c && tmp[all[2]] != '\0')
		{
			res[all[0]][all[1]++] = tmp[all[2]];
			all[2]++;
		}
		res[all[0]++][all[1]] = '\0';
	}
	free(tmp);
	return (res);
}
