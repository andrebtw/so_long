/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_rect_walls.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:03:37 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/07 15:44:25 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	check_if_rectangular(char **map)
{
	t_map	mapc;
	int		saved_length;

	saved_length = 0;
	mapc.y = 0;
	while (map[mapc.y])
	{
		mapc.x = 0;
		while (map[mapc.y][mapc.x])
			mapc.x++;
		if (mapc.y && saved_length != mapc.x)
		{
			error_printing("The map is not rectangular",
				"Make sure the map has a rectangular format.",
				"\n\n111111\n1PCCE1\n111111");
			return (ERROR);
		}
		saved_length = mapc.x;
		mapc.y++;
	}
	return (0);
}

int	check_wall_first_last_line(char **map, t_map mapc)
{
	mapc.x = 0;
	while (map[0][mapc.x])
	{
		//ft_printf("%c", map[0][mapc.x]);
		if (map[0][mapc.x] != '1' && map[0][mapc.x] != '\n')
			return (ERROR);
		mapc.x++;
	}
	mapc.x = 0;
	while (map[mapc.y - 1][mapc.x])
	{
		if (map[mapc.y - 1][mapc.x] != '1' && map[mapc.y - 1][mapc.x] != '\n')
			return (ERROR);
		mapc.x++;
	}
	return (0);
}

int	check_walls(char **map)
{
	t_map	mapc;

	mapc.y = 0;
	while (map[mapc.y])
	{
		if (map[mapc.y][0] != '1')
			return (error_printing("The walls do not close the map.",
					"Make sure the walls close the entire map.",
					"\n\n111111\n1PCCE1\n111111"), ERROR);
		mapc.x = 0;
		while (map[mapc.y][mapc.x])
			mapc.x++;
		if (map[mapc.y][mapc.x - 2] != '1')
			return (error_printing("The walls do not close the map.",
					"Make sure the walls close the entire map.",
					"\n\n111111\n1PCCE1\n111111"), ERROR);
		mapc.y++;
	}
	if (check_wall_first_last_line(map, mapc) == ERROR)
			return (error_printing("The walls do not close the map.",
					"Make sure the walls close the entire map.",
					"\n\n111111\n1PCCE1\n111111"), ERROR);
	return (0);
}
