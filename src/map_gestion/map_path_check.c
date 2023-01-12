/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:20:28 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/12 13:59:36 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	findpath(t_map_info map, char **path, int *end_pos)
{
	int	var;

	if (map.p_index_y == end_pos[0] && map.p_index_x == end_pos[1])
		return (1);
	if (path[map.p_index_y][map.p_index_x] == '0' ||
		path[map.p_index_y][map.p_index_x] == 'P')
	{
		if (path[map.p_index_y + 1][map.p_index_x] == '0' ||
			path[map.p_index_y + 1][map.p_index_x] == 'C')
		{
			path[map.p_index_y][map.p_index_x] = '2';
			map.p_index_y++;
			var = findpath(map, path, end_pos);
			if (var == -1)
				map.p_index_y--;
			if (var == 1)
				return (1);
		}
		if (path[map.p_index_y][map.p_index_x + 1] == '0' ||
			path[map.p_index_y][map.p_index_x + 1] == 'C')
		{
			path[map.p_index_y][map.p_index_x] = '2';
			map.p_index_x++;
			var = findpath(map, path, end_pos);
			if (var == -1)
				map.p_index_x--;
			if (var == 1)
				return (1);
		}
		if (path[map.p_index_y - 1][map.p_index_x] == '0' ||
			path[map.p_index_y - 1][map.p_index_x] == 'C')
		{
			path[map.p_index_y][map.p_index_x] = '2';
			map.p_index_y--;
			var = findpath(map, path, end_pos);
			if (var == -1)
				map.p_index_y++;
			if (var == 1)
				return (1);
		}
		if (path[map.p_index_y][map.p_index_x - 1] == '0' ||
			path[map.p_index_y][map.p_index_x - 1] == 'C')
		{
			path[map.p_index_y][map.p_index_x] = '2';
			map.p_index_x--;
			var = findpath(map, path, end_pos);
			if (var == -1)
				map.p_index_x++;
			if (var == 1)
				return (1);
		}
		if (map.p_index_y == end_pos[0] && map.p_index_x == end_pos[1])
			return (1);
		if (path[map.p_index_y - 1][map.p_index_x] == '2')
			return (-1);
		if (path[map.p_index_y][map.p_index_x - 1] == '2')
			return (-1);
		if (path[map.p_index_y + 1][map.p_index_x] == '2')
			return (-1);
		if (path[map.p_index_y][map.p_index_x + 1] == '2')
			return (-1);
	}
	return (0);
}

int	path_check_loop(char *file, int **c_coords, t_map_info mapi)
{
	int		i;
	int		not_end;
	char	**map_copy;

	i = 0;
	not_end = 1;
	while (c_coords[i] && not_end)
	{
		if (!c_coords[i])
			not_end = 0;
		map_copy = map_opening(file);
		if (!map_copy)
			return (MALLOC_ERROR);
		if (not_end)
			if (findpath(mapi, map_copy, c_coords[i]) != 1)
				return (tab_free(map_copy), tab_free_int(c_coords), ERROR);
		if (!not_end)
		{
			c_coords[0][0] = mapi.e_index_y;
			c_coords[0][1] = mapi.e_index_x;
			if (findpath(mapi, map_copy, c_coords[0]) != 1)
				return (tab_free(map_copy), tab_free_int(c_coords), ERROR);
		}
		tab_free(map_copy);
		i++;
	}
	return (0);
}

int	path_check(char **map, char *file)
{
	t_map_info	mapi;
	t_map		mapc;
	int			**c_coords;

	mapc.x = 0;
	mapc.y = 0;
	mapi.c_count = count_c(map, mapc);
	mapi = find_e_index(map, mapc, mapi);
	mapi = find_p_index(map, mapc, mapi);
	c_coords = get_collectibles(map);
	if (path_check_loop(file, c_coords, mapi) != 1)
		return (tab_free_int(c_coords), ERROR);
	tab_free_int(c_coords);
	return (0);
}
