/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavas <tyavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 00:20:40 by jrameau           #+#    #+#             */
/*   Updated: 2023/05/03 21:47:40 by tyavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*list;

	if (!lst)
		return (NULL);
	list = f(lst);
	new = list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(list->next == f(lst)))
		{
			free(list->next);
			return (NULL);
		}
		list = list->next;
	}
	return (new);
}
