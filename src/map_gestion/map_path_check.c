/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:20:28 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/21 22:09:28 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"
/*
int	findpath(t_map_info map)
{
	int	var;

	if (map.p_index_y == end.y && map.p_index_x == end.x)
		return (1);
	if (path[map.p_index_y][map.p_index_x] == 0)
	{
		if (path[map.p_index_y + 1][map.p_index_x] == 0)
		{
			path[map.p_index_y][map.p_index_x] = 2;
			map.p_index_y++;
			var = findpath(map);
			if (var == -1)
				map.p_index_y--;
			if (var == 1)
				return (1);
		}
		if (path[map.p_index_y][map.p_index_x + 1] == 0)
		{
			path[map.p_index_y][map.p_index_x] = 2;
			map.p_index_x++;
			var = findpath(map);
			if (var == -1)
				map.p_index_x--;
			if (var == 1)
				return (1);
		}
		if (path[map.p_index_y - 1][map.p_index_x] == 0)
		{
			path[map.p_index_y][map.p_index_x] = 2;
			map.p_index_y--;
			var = findpath(map);
			if (var == -1)
				map.p_index_y++;
			if (var == 1)
				return (1);
		}
		if (path[map.p_index_y][map.p_index_x - 1] == 0)
		{
			path[map.p_index_y][map.p_index_x] = 2;
			map.p_index_x--;
			var = findpath(map);
			if (var == -1)
				map.p_index_x++;
			if (var == 1)
				return (1);
		}
		if (map.p_index_y == end.y && map.p_index_x == end.x)
			return (1);
		if (path[map.p_index_y - 1][map.p_index_x] == 2)
			return (-1);
		if (path[map.p_index_y][map.p_index_x - 1] == 2)
			return (-1);
		if (path[map.p_index_y + 1][map.p_index_x] == 2)
			return (-1);
		if (path[map.p_index_y][map.p_index_x + 1] == 2)
			return (-1);
	}
	return (0);
}*/

int	path_check(char **map)
{
	t_map_info 	mapi;
	t_map		mapc;
	int			**c_coords;

	mapc.x = 0;
	mapc.y = 0;
	mapi.c_count = count_c(map, mapc);
	mapi = find_e_index(map, mapc, mapi);
	mapi = find_p_index(map, mapc, mapi);
	c_coords = get_collectibles(map);
	tab_free_int(c_coords);
	return (0);
}
