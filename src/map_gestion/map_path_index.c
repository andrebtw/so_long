/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:03:34 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/09 13:04:12 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_map_info	find_p_index(char **map, t_map mapc, t_map_info mapi)
{
	mapc.y = 0;
	mapc.x = 0;
	while (map[mapc.y])
	{
		mapc.x = 0;
		while(map[mapc.y][mapc.x])
		{
			if (map[mapc.y][mapc.x] == 'P')
			{
				mapi.p_index_x = mapc.x;
				mapi.p_index_y = mapc.y;
				break;
			}
			mapc.x++;
		}
		mapc.y++;
	}
	return (mapi);
}

t_map_info	find_e_index(char **map, t_map mapc, t_map_info mapi)
{
	mapc.y = 0;
	mapc.x = 0;
	while (map[mapc.y])
	{
		mapc.x = 0;
		while(map[mapc.y][mapc.x])
		{
			if (map[mapc.y][mapc.x] == 'E')
			{
				mapi.e_index_x = mapc.x;
				mapi.e_index_y = mapc.y;
				break;
			}
			mapc.x++;
		}
		mapc.y++;
	}
	return (mapi);
}

int	count_c(char **map, t_map mapc)
{
	int	count;

	count = 0;
	mapc.y = 0;
	mapc.x = 0;
	while (map[mapc.y])
	{
		mapc.x = 0;
		while(map[mapc.y][mapc.x])
		{
			if (map[mapc.y][mapc.x] == 'C')
				count++;
			mapc.x++;
		}
		mapc.y++;
	}
	return (count);
}
