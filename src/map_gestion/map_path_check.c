/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:20:28 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/10 11:01:46 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	backtracking(char **map, t_map mapc, t_map_info mapi, int count)
{
	if (map[mapc.y][mapc.x] == 'E' && mapi.c_count == count)
		return (1);
	else if 
}

int	path_finding(char **map, t_map mapc, t_map_info mapi)
{
	int	count;

	count = 0;
	mapc.x = 0;
	mapc.y = 0;
	backtracking(map, mapc, mapi, count);
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
