/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalju-be <jalju-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:40:00 by jalju-be          #+#    #+#             */
/*   Updated: 2025/08/30 17:24:54 by jalju-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*node;
	void	*tmp;

	head = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		tmp = f(lst->content);
		if(!tmp)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		node = ft_lstnew(tmp);
		if (node == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, node);
		lst = lst->next;
	}
	return (head);
}
