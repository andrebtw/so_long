/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:23:43 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/09 18:15:42 by anrodri2         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_int(const char *s)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	src_size;
	unsigned int	dest_size;

	src_size = 0;
	dest_size = 0;
	if (size == 0)
		return (ft_strlen_int(src));
	if ((int)size < 0)
		size = ft_strlen_int(src) + 1;
	while (src[src_size] != '\0' && (int)size - 1 > 0)
	{
		dst[dest_size] = src[src_size];
		dest_size++;
		src_size++;
		size--;
	}
	dst[dest_size] = '\0';
	return (ft_strlen_int(src));
}
