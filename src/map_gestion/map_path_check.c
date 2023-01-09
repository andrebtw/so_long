/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:20:28 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/09 11:55:02 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

typedef struct t_map_info
{
	char	**p_index;
	char	**e_index;
}	s_map_info;

char	*find_p_index(char **map, t_map mapc)
{
	mapc.y = 0;
	mapc.x = 0;

	while (map[mapc.y])
	{
		mapc.x = 0;
		while(map[mapc.y][mapc.x])
		{
			if (map[mapc.y][mapc.x] == 'P')
				return (&map[mapc.y][mapc.x]);
			mapc.x++;
		}
		mapc.y++;
	}
	return (NULL);
}

char	*find_e_index(char **map, t_map mapc)
{
	mapc.y = 0;
	mapc.x = 0;

	while (map[mapc.y])
	{
		mapc.x = 0;
		while(map[mapc.y][mapc.x])
		{
			if (map[mapc.y][mapc.x] == 'E')
				return (&map[mapc.y][mapc.x]);
			mapc.x++;
		}
		mapc.y++;
	}
	return (NULL);
}

int	count_c(char **map, t_map mapc)
{
	int	count;

	count = 0;
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
	t_map	mapc;
	int		c_count;

	mapc.y = 0;
	c_count = count_c(map, mapc);
	ft_printf("%c", find_e_index);
	return (0);
}
