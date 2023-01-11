/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:35:30 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/11 13:03:52 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int path[5][5] = {
	1, 1, 1, 1, 1,
	1, 0, 1, 0, 1, 
	1, 0, 0, 0, 1,
	1, 1, 0, 0, 1,
	1, 1, 1, 1, 1
};

typedef struct s_map
{
	int	y;
	int	x;
}	t_map;

int	findpath(t_map map, t_map end)
{
	if (map.y == end.y && map.x == end.x)
		return (1);
	if (path[map.y][map.x] == 0 || path[map.y][map.x] == 2)
	{
		if (path[map.y + 1][map.x] == 0 || path[map.y + 1][map.x] == 2)
		{
			path[map.y][map.x] = 2;
			map.y++;
			return (findpath(map, end));
		}
		if (path[map.y][map.x + 1] == 0 || path[map.y][map.x + 1] == 2)
		{
			path[map.y][map.x] = 2;
			map.x++;
			return (findpath(map, end));
		}
		if (path[map.y - 1][map.x] == 0 || path[map.y - 1][map.x] == 2)
		{
			path[map.y][map.x] = 2;
			map.y--;
			return (findpath(map, end));
		}
		if (path[map.y][map.x - 1] == 0 || path[map.y][map.x - 1] == 2)
		{
			path[map.y][map.x] = 2;
			map.x--;
			return (findpath(map, end));
		}
	}
	return (0);
}

int	main(void)
{
	t_map map;
	t_map end;

	map.y = 1;
	map.x = 1;
	end.y = 1;
	end.x = 3;
	printf("%d", findpath(map, end));
	return (0);
}
