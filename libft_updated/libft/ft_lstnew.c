/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:51:24 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/22 15:54:49 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*r_value;

	r_value = malloc (sizeof(t_list));
	if (!r_value)
		return (NULL);
	r_value->content = content;
	r_value->next = NULL;
	return (r_value);
}
