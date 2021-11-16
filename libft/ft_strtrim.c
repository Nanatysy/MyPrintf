#include "libft.h"

static int	ft_find(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		begin;
	int		end;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (ft_find(set, s1[i]) && s1[i + 1] != '\0')
		i++;
	begin = i;
	i = ft_strlen(s1) - 1;
	while (ft_find(set, s1[i]) && i > begin)
		i--;
	end = i;
	if (begin == end && ft_find(set, s1[i]))
		begin++;
	res = (char*)malloc(end - begin + 2);
	i = 0;
	if (!res)
		return (NULL);
	while (begin <= end)
		res[i++] = s1[begin++];
	res[i] = '\0';
	return (res);
}
