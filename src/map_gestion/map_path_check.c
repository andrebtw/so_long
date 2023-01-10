/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:20:28 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/10 11:37:36 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	backtracking(char **map, t_map mapc, t_map_info mapi, int **path)
{
	
}

int	path_finding(char **map, t_map mapc, t_map_info mapi)
{
	int	count;
	int	path[tab_size(map)][ft_strlen(map[0])];

	count = tab_size(map);
	while (count)
	{
		ft_memset(path[count - 1], 0, ft_strlen())
	}
	mapc.x = 0;
	mapc.y = 0;
	backtracking(map, mapc, mapi);
	return (0);
}

int	path_check(char **map)
{
	t_map		mapc;
	t_map_info 	mapi;

	mapi.c_count = count_c(map, mapc);
	mapi = find_e_index(map, mapc, mapi);
	mapi = find_p_index(map, mapc, mapi);
	if (path_finding(map, mapc, mapi) == ERROR)
		return (ERROR);
	return (0);
}
