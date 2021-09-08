/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <dwillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:52:49 by dwillett          #+#    #+#             */
/*   Updated: 2020/11/07 16:45:48 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
