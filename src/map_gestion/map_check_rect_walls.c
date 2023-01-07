/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_rect_walls.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:03:37 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/07 11:37:41 by anrodri2         ###   ########.fr       */
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

int	check_walls(char **map)
{
	return (0);
}
