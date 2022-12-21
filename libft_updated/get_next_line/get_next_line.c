/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:28:03 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/13 08:42:18 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*back_up_string(char *s, int is_saved_string)
{
	int		i;
	int		j;
	char	*r_string;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i])
		i++;
	r_string = (char *) malloc (strlen_gnl(s, 0) - strlen_gnl(s, 1) + 1);
	if (!r_string)
	{
		if (is_saved_string)
			free(s);
		return (NULL);
	}
	j = 0;
	while (s[i])
		r_string[j++] = s[i++];
	free(s);
	r_string[j] = '\0';
	return (r_string);
}

char	*save_static(char *temp_string, char *stash,
		char *saved_string, int read_output)
{
	if (!read_output && (!stash[0]))
	{
		free(temp_string);
		free(saved_string);
		saved_string = NULL;
		return (NULL);
	}
	if (read_output != NOT_READ)
	{
		free(saved_string);
		saved_string = NULL;
		saved_string = back_up_string(temp_string, 0);
		if (!saved_string)
			return (free(temp_string), free(saved_string), NULL);
	}
	else
	{
		saved_string = back_up_string(saved_string, 1);
		if (!saved_string)
			return (free(temp_string), free(saved_string), NULL);
		free(temp_string);
	}
	return (saved_string);
}

char	*temp_string(char *temp_s)
{
	free(temp_s);
	temp_s = (char *) ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	if (!temp_s)
		return (NULL);
	return (temp_s);
}

char	*main_func(int fd, char *r_s, char *temp_s, int read_output)
{
	static char	*savd_s;

	savd_s = static_init(fd, savd_s, r_s, temp_s);
	if (!savd_s)
		return (NULL);
	r_s = ft_strjoin_gnl(r_s, savd_s);
	if (!r_s)
		return (free(temp_s), free(savd_s), savd_s = NULL, NULL);
	if (strlen_gnl(savd_s, 0) != strlen_gnl(savd_s, 1))
		fd = -2;
	while (fd != -2)
	{
		temp_s = temp_string(temp_s);
		if (!temp_s)
			return (free(r_s), free(savd_s), savd_s = NULL, NULL);
		read_output = read(fd, temp_s, BUFFER_SIZE);
		if (read_output == -1)
			return (free(temp_s), free(r_s), free(savd_s), savd_s = NULL, NULL);
		if (strlen_gnl(temp_s, 0) != strlen_gnl(temp_s, 1) || read_output == 0)
			fd = -2;
		r_s = ft_strjoin_gnl(r_s, temp_s);
		if (!r_s)
			return (free(temp_s), free(savd_s), savd_s = NULL, NULL);
	}
	return (savd_s = save_static(temp_s, r_s, savd_s, read_output), r_s);
}

char	*get_next_line(int fd)
{
	char		*temp_s;
	char		*r_s;

	r_s = (char *) ft_calloc_gnl(1, sizeof(char));
	temp_s = (char *) ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	if ((!r_s || !temp_s))
		return (failed_malloc(r_s, temp_s),
			main_func(-1, NULL, NULL, NOT_READ), NULL);
	r_s = main_func(fd, r_s, temp_s, NOT_READ);
	if (!r_s)
		return (main_func(-1, NULL, NULL, NOT_READ), NULL);
	if (r_s && r_s[0] == '\0')
		return (free(r_s), NULL);
	return (r_s);
}
