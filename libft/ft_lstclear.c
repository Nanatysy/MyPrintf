#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*ntmp;

	if (lst == NULL)
		return ;
	tmp = *lst;
	while (tmp)
	{
		ntmp = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = ntmp;
	}
	*lst = NULL;
}
