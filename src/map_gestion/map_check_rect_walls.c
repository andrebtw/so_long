/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_rect_walls.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:03:37 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/07 14:42:03 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

// Last line of file doesn't have \n
int	check_if_rect_error(t_map mapc, int saved_length, char **map)
{
	if (map[mapc.y + 1] && (mapc.y && saved_length != mapc.x))
	{
		error_printing("The map is not rectangular",
			"Make sure the map has a rectangular format.",
			"\n\n111111\n1PCCE1\n111111");
		return (ERROR);
	}
	else if (!map[mapc.y + 1] && (mapc.y && saved_length != mapc.x + 1))
	{
		error_printing("The map is not rectangular",
			"Make sure the map has a rectangular format.",
			"\n\n111111\n1PCCE1\n111111");
		return (ERROR);
	}
	return (0);
}

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
		if (check_if_rect_error(mapc, saved_length, map) == ERROR)
			return (ERROR);
		saved_length = mapc.x;
		mapc.y++;
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
	return (0);
}
