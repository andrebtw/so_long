/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:20:28 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/17 14:32:23 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	path_check_loop(char *file, int **c_coords, t_map_info mapi)
{
	int		i;
	char	**map_copy;

	i = 0;
	while (mapi.c_count != 0)
	{
		map_copy = map_opening(file);
		if (!map_copy)
			return (MALLOC_ERROR);
		if (findpath(mapi, map_copy, c_coords[i], "0CP") != 1)
			return (tab_free(map_copy), tab_free_int(c_coords), ERROR);
		tab_free(map_copy);
		i++;
		mapi.c_count--;
	}
	c_coords[0][0] = mapi.e_index_y;
	c_coords[0][1] = mapi.e_index_x;
	map_copy = map_opening(file);
	if (!map_copy)
		return (MALLOC_ERROR);
	if (findpath(mapi, map_copy, c_coords[0], "0CPE") != 1)
		return (tab_free(map_copy), tab_free_int(c_coords), ERROR);
	tab_free(map_copy);
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
	if (path_check_loop(file, c_coords, mapi) == ERROR)
		return (ERROR);
	tab_free_int(c_coords);
	return (0);
}
