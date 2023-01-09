/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:20:28 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/09 13:00:53 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

typedef struct s_map_info
{
	int	p_index_x;
	int	p_index_y;
	int	e_index_x;
	int	e_index_y;
	int	c_count;
}	t_map_info;

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

int	path_check(char **map)
{
	t_map		mapc;
	t_map_info 	mapi;

	mapi.c_count = count_c(map, mapc);
	mapi = find_e_index(map, mapc, mapi);
	mapi = find_p_index(map, mapc, mapi);
	/*ft_printf("%c test", map[mapi.e_index_y][mapi.e_index_x]);
	ft_printf("%c test", map[mapi.p_index_y][mapi.p_index_x]);
	*/
	printf("%d", mapi.c_count);
	return (0);
}
