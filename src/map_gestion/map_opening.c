/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_opening.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:09:10 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/26 19:09:10 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	free_all(char	**map_points, int y)
{
	int	index;

	index = 0;
	while (index <= y)
	{
		free(map_points[index]);
		index++;
	}
	free(map_points);
}


char	**reading_loop(int fd)
{
	char	**map_points;
	char	*temp_string;
	int		y;

	y = 0;
	temp_string = (void *)1;
	map_points = malloc (9000);
	map_points[0] = malloc (100);
	map_points[1] = malloc (100);
	map_points[2] = malloc (100);
	map_points[3] = malloc (100);
	map_points[4] = malloc (100);
	map_points[5] = malloc (100);
	map_points[6] = malloc (100);
	map_points[7] = malloc (100);
	map_points[8] = malloc (100);

	while (temp_string)
	{
		temp_string = get_next_line(fd);
		if (temp_string)
		{
			ft_memmove(map_points[y], temp_string, ft_strlen(temp_string) + 1);
			free(temp_string);
		}
		y++;
	}
	map_points[y] = NULL;
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
