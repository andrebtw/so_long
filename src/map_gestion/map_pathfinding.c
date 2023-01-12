/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pathfinding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:27:53 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/12 16:54:02 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	check_back(char **path, t_map_info map, int *end_pos)
{
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
	return (0);
}

int	findpath(t_map_info map, char **path, int *end_pos, char *allowed_chars)
{
	if (map.p_index_y == end_pos[0] && map.p_index_x == end_pos[1])
		return (1);
	if (ft_strchr(allowed_chars, path[map.p_index_y][map.p_index_x]))
	{
		if (ft_strchr(allowed_chars, path[map.p_index_y + 1][map.p_index_x]))
		{
			path[map.p_index_y][map.p_index_x] = '2';
			map.p_index_y++;
			if (findpath(map, path, end_pos, allowed_chars) == -1)
				map.p_index_y--;
			else
				return (1);
		}
		if (ft_strchr(allowed_chars, path[map.p_index_y][map.p_index_x + 1]))
		{
			path[map.p_index_y][map.p_index_x] = '2';
			map.p_index_x++;
			if (findpath(map, path, end_pos, allowed_chars) == -1)
				map.p_index_x--;
			else
				return (1);
		}
		if (ft_strchr(allowed_chars, path[map.p_index_y - 1][map.p_index_x]))
		{
			path[map.p_index_y][map.p_index_x] = '2';
			map.p_index_y--;
			if (findpath(map, path, end_pos, allowed_chars) == -1)
				map.p_index_y++;
			else
				return (1);
		}
		if (ft_strchr(allowed_chars, path[map.p_index_y][map.p_index_x - 1]))
		{
			path[map.p_index_y][map.p_index_x] = '2';
			map.p_index_x--;
			if (findpath(map, path, end_pos, allowed_chars) == -1)
				map.p_index_x++;
			else
				return (1);
		}
	}
	return (check_back(path, map, end_pos));
}
