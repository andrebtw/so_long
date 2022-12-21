/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:35:35 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/10 14:52:59 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	size_count(char *dst, const char *src, size_t size)
{
	int		dst_size;
	int		src_size;
	size_t	size_count;

	dst_size = 0;
	src_size = 0;
	size_count = size;
	while (dst[dst_size] != '\0' && size_count > 0)
	{
		dst_size++;
		size_count--;
	}
	while (src[src_size] != '\0')
		src_size++;
	if (size == 0)
		return (src_size);
	if ((int)size < 0)
		return (src_size + dst_size);
	if (dst_size >= (int)size)
		return (size + src_size);
	else
		return (dst_size + src_size);
}

static size_t	ft_size_add_null_char(char *dst, int index, size_t return_size)
{
	dst[index] = '\0';
	return (return_size);
}

static size_t	ft_size_check(size_t size, size_t return_size)
{
	if ((int)size < 0)
		return (return_size + 1);
	return (size);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	src_size;
	unsigned int	dest_size;
	size_t			return_size;

	if (dst == NULL && size == 0)
		return (0);
	return_size = size_count(dst, src, size);
	src_size = 0;
	dest_size = 0;
	size = ft_size_check(size, return_size);
	while (dst[dest_size] != '\0')
	{
		dest_size++;
		if (size == 0)
			return (return_size);
		size--;
	}
	while ((int)size - 1 > 0 && src[src_size] != '\0')
	{
		dst[dest_size] = src[src_size];
		dest_size++;
		src_size++;
		size--;
	}
	return (ft_size_add_null_char(dst, dest_size, return_size));
}
