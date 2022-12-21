/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:20:19 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/22 15:09:03 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_size_verif(const char *s, unsigned int start, size_t len)
{
	char	*ver_string;

	if (len >= ft_strlen(s) - start)
	{
		ver_string = (char *) malloc (
				(ft_strlen(s) - start) * sizeof(char) + 1);
	}
	else
		ver_string = (char *) malloc (len * sizeof(char) + 1);
	return (ver_string);
}

static char	*ft_zero_size(void)
{
	char	*r_string;

	r_string = (char *) malloc (sizeof(char));
	if (r_string == NULL)
		return (NULL);
	r_string[0] = '\0';
	return (r_string);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			len_count;
	char			*r_string;

	i = start;
	len_count = 0;
	if ((unsigned int)ft_strlen(s) <= start)
		return (ft_zero_size());
	r_string = ft_size_verif(s, start, len);
	if (r_string == NULL)
		return (NULL);
	while (s[i] != '\0' && len_count < len)
	{
		r_string[len_count] = s[i];
		len_count++;
		i++;
	}
	if (r_string[len_count] != '\0')
		r_string[len_count] = '\0';
	return (r_string);
}
