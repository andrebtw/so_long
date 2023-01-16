/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:56:29 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/16 15:58:15 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_strlen_int(char *s)
{
	int	index;

	index = 0;
	if (!s)
		return (0);
	while (s[index] != '\0')
		index++;
	return (index);
}

void	free_strings(char *s1, char *s2, int free_one, int free_two)
{
	if (free_one != 0)
		free(s1);
	if (free_two != 0)
		free(s2);
}

char	*ft_strjoin_free(char *s1, char *s2, int free_one, int free_two)
{
	char	*r_string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	r_string = (char *) malloc (ft_strlen_int(s1) + ft_strlen_int(s2) + 1);
	if (r_string == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		r_string[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		r_string[j] = s2[i];
		i++;
		j++;
	}
	r_string[j] = '\0';
	return (free_strings(s1, s2, free_one, free_two), r_string);
}
