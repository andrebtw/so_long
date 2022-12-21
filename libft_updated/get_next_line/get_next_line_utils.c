/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:31:43 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/13 08:42:08 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	failed_malloc(char *temp_string, char *r_string)
{
	if (!temp_string)
		if (r_string)
			free(r_string);
	if (!r_string)
		if (temp_string)
			free(temp_string);
}

void	*ft_calloc_gnl(size_t count, size_t size)
{
	unsigned char	*array;
	size_t			i;
	size_t			k;

	k = 0;
	if (size)
		if (SIZE_MAX / size <= count)
			return (NULL);
	array = (unsigned char *) malloc ((count * size));
	if (array == NULL)
		return (NULL);
	i = count * size;
	while (k < i)
	{
		array[k] = '\0';
		k++;
	}
	return ((void *)array);
}

size_t	strlen_gnl(const char *s, int check_if_endl)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (check_if_endl && s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*r_string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (strlen_gnl(s2, 0) == strlen_gnl(s2, 1))
		r_string = (char *) malloc (
				strlen_gnl(s1, 0) + strlen_gnl(s2, 1) + 1);
	else
		r_string = (char *) malloc (
				strlen_gnl(s1, 0) + strlen_gnl(s2, 1) + 2);
	if (r_string == NULL)
		return (free(s1), NULL);
	while (s1[i] != '\0')
		r_string[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0' && s2[i] != '\n')
		r_string[j++] = s2[i++];
	if (s2[i] == '\n')
		r_string[j++] = '\n';
	return (free(s1), r_string[j] = '\0', r_string);
}

char	*static_init(int free_static, char *savd_s, char *r_s, char *temp_s)
{
	if (free_static == -1)
	{
		if (r_s)
			free(r_s);
		if (temp_s)
			free(temp_s);
		return (free(savd_s), NULL);
	}
	if (!savd_s)
		savd_s = (char *) ft_calloc_gnl(1, sizeof(char));
	if (!savd_s)
		return (free(temp_s), free(r_s), savd_s = NULL);
	return (savd_s);
}
