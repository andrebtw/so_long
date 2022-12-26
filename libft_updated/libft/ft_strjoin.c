/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:59:04 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/10 17:44:41 by anrodri2         ###   ########.fr       */
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

static void	free_options(int free_first, int free_second, char *s1, char *s2)
{
	if (free_first > 0 && s1)
		free(s1);
	if (free_second > 0 && s2)
		free(s2);
}

char	*ft_strjoin(char *s1, char *s2, int free_first, int free_second)
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
	return (free_options(free_first, free_second, s1, s2), r_string);
}
