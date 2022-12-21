/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:55:20 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/24 13:17:15 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*r_lst;
	t_list	*r_node;

	r_lst = NULL;
	while (lst != NULL)
	{
		r_node = ft_lstnew(f(lst->content));
		if (!r_node)
		{
			ft_lstclear(&r_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&r_lst, r_node);
		lst = lst->next;
	}
	return (r_lst);
}
