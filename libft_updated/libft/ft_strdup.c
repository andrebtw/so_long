/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:46:13 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/09 10:12:40 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*return_string;
	unsigned int	i;
	unsigned int	string_size;

	string_size = 0;
	while (s[string_size] != '\0')
		string_size++;
	return_string = (char *) malloc(string_size * sizeof(char) + 1);
	if (return_string == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		return_string[i] = s[i];
		i++;
	}
	return_string[i] = '\0';
	return (return_string);
}
