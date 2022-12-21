/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:20:28 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/21 17:28:51 by anrodri2         ###   ########.fr       */
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

void print_map(char **map)
{
	int y = 0; 
	int x = 0;

	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			ft_printf("%c", map[y][x]);
			x++;
		}
		y++;
	}
}

int	path_check(char **map, char *file)
{
	t_map_info	mapi;
	t_map		mapc;
	int			**c_coords;
	char		**map_copy;

	mapc.x = 0;
	mapc.y = 0;
	mapi.c_count = count_c(map, mapc);
	mapi = find_e_index(map, mapc, mapi);
	mapi = find_p_index(map, mapc, mapi);
	c_coords = get_collectibles(map);
	int i = 0;
	while (c_coords[i])
	{
		map_copy = map_opening(file);
		if (!map_copy)
			return (MALLOC_ERROR);
		if (findpath(mapi, map_copy, c_coords[i]) != 1)
		{
			//ft_printf("ERROR OF PATH LOL");
			print_map(map_copy);
			tab_free(map_copy);
			return (tab_free_int(c_coords), ERROR);
		}
		print_map(map_copy);
		tab_free(map_copy);
		//ft_printf("y : %d ; x : %d\n", c_coords[i][0], c_coords[i][1]);
		i++;
	}
	ft_printf("C count : %d\n", mapi.c_count);
	tab_free_int(c_coords);
	return (0);
}
