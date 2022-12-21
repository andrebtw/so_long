/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:22:56 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/10 14:29:43 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*string_dest;
	const char	*string_src;

	string_src = src;
	string_dest = dest;
	i = 0;
	if (dest == NULL && src == NULL)
	{
		string_dest = NULL;
		return (dest);
	}
	while (i < n)
	{
		string_dest[i] = string_src[i];
		i++;
	}
	return (dest);
}
