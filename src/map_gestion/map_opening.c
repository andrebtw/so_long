/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_opening.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:09:10 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/07 15:03:02 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*add_endl(char *string)
{
	size_t	i;
	char	*r_string;

	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	if (ft_strlen(string) == i)
	{
		r_string = ft_strjoin(string, "\n");
		free(string);
		if (!r_string)
			return (NULL);
		return (r_string);
	}
	r_string = string;
	return (r_string);
}

void	tab_free(char **tab)
{
	int	y;

	y = 0;
	while (tab[y])
	{
		free(tab[y]);
		y++;
	}
	free(tab);
}

char	**update_tab(char **map_points, int y, char *temp_string)
{
	char	**r_value;
	int		i;

	i = 0;
	r_value = (char **) malloc ((y + 2) * sizeof(char **));
	if (!r_value)
		return (tab_free(map_points), NULL);
	while (i < y)
	{
		r_value[i] = (char *) malloc (ft_strlen(map_points[i]) + 1);
		if (!r_value)
			return (tab_free(map_points), tab_free(r_value), NULL);
		ft_memmove(r_value[i], map_points[i], ft_strlen(map_points[i]) + 1);
		free(map_points[i]);
		i++;
	}
	r_value[y] = (char *) malloc (ft_strlen(temp_string) + 1);
	if (!r_value)
		return (tab_free(map_points), tab_free(r_value), NULL);
	ft_memmove(r_value[y], temp_string, ft_strlen(temp_string) + 1);
	return (free(map_points), r_value);
}

char	**reading_loop(int fd)
{
	char	**map_points;
	char	*temp_string;
	int		y;

	y = 0;
	temp_string = (void *)1;
	map_points = (char **) malloc (2 * sizeof(char **));
	if (!map_points)
		return (NULL);
	while (temp_string)
	{
		temp_string = get_next_line(fd);
		if (temp_string)
		{
			temp_string = add_endl(temp_string);
			if (!temp_string)
				return (NULL);
			map_points = update_tab(map_points, y, temp_string);
			free(temp_string);
		}
		y++;
	}
	map_points[y - 1] = NULL;
	return (map_points);
}

char	**map_opening(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		error_printing("File not found.",
			"Make sure the file exists.", "./so_long map.ber");
		return (NULL);
	}
	return (reading_loop(fd));
}
