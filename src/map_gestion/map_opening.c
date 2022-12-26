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

char	**reading_loop(char **map_points, char *temp_string, int y, int fd)
{
	char	*main_string;

	main_string = (char *) malloc (sizeof(char) * 1);
	if (!main_string)
		return (NULL);
	while (temp_string)
	{
		temp_string = get_next_line(fd);
		//temp_string = ft_strjoin(temp_string, ";", 1, 0);
		if (temp_string[0] != '\0')
			main_string = ft_strjoin(main_string, temp_string, 1, 1);
		y++;
	}
	map_points = ft_split(main_string, ';');
	return (map_points);
}

char	**map_opening(char *file)
{
    int		fd;
	char	**map_points;
	int		y;
	char	*temp_string;

	temp_string = (char *) malloc (sizeof(char) * 1);
	if (!temp_string)
		return (NULL);
	map_points = (char **) malloc(1 * sizeof(char **));
	if (!map_points)
		return (NULL);
	y = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		error_printing("File not found.", "Make sure the file exists.", "./so_long map.ber");
		return (NULL);
	}
	return (reading_loop(map_points, temp_string, y, fd));
}
