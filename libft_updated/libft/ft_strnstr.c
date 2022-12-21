/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:08:01 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/11 11:38:47 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_size(size_t size)
{
	if ((long long)size < 0)
		return ((long long)__LONG_LONG_MAX__);
	return ((long long)size);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	n = ft_size(n) + 1;
	if (!needle[0])
		return ((char *)haystack);
	while (--n > 0 && haystack[i] != '\0')
	{
		j = 0;
		while ((haystack[i] == needle[j] && needle[j] != '\0'))
		{
			i++;
			j++;
		}
		if (needle[j] == '\0' && (long long)n - (long long)j >= 0)
			return ((char *)haystack + (i - j));
		else
		{
			i = i - j;
			j = 0;
		}
		i++;
	}
	return (NULL);
}
