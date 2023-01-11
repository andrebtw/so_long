/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_cords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:26:50 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/11 17:47:57 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	tab_free_int(int **tab)
{
	int	y;

	y = 0;
	while (tab[y])
	{
		free(tab[y]);
		y++;
	}
	free(tab[y]);
	free(tab);
}

size_t	tab_len(int	**tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

int	**add_element(int **points, int y, int x)
{
	int	i;
	int	**new_points;

	i = -1;
	new_points = (int **) malloc (sizeof(int **) * (tab_len(points) + 2));
	while (points[++i])
	{
		new_points[i] = (int *) malloc (sizeof(int) * 2);
		if (!new_points[i])
			return (tab_free_int(new_points), NULL);
		new_points[i][0] = points[i][0];
		new_points[i][1] = points[i][1];
	}
	new_points[i] = (int *) malloc (sizeof(int) * 2);
	if (!new_points)
		return (tab_free_int(new_points), NULL);
	new_points[i][0] = y;
	new_points[i][1] = x;
	new_points[i + 1] = (int *) malloc (sizeof(int) * 2);
	if (!new_points)
		return (tab_free_int(new_points), NULL);
	free(new_points[i + 1]);
	new_points[i + 1] = NULL;
	tab_free_int(points);
	return (new_points);
}

int	**get_loop(char **map, int	**points, t_map mapc)
{
	while (map[mapc.y])
	{
		mapc.x = 0;
		while (map[mapc.y][mapc.x])
		{
			if (map[mapc.y][mapc.x] == 'C')
			{
				points = add_element(points, mapc.y, mapc.x);
				if (!points)
					return (NULL);
			}
			mapc.x++;
		}
		mapc.y++;
	}
	return (points);
}

int	**get_collectibles(char **map)
{
	int		**points;
	t_map	mapc;

	points = (int **) malloc (sizeof(int **) * 1);
	if (!points)
		return (NULL);
	points[0] = (int *) malloc (sizeof(int *) * 1);
	if (!points[0])
		return (free(points), NULL);
	free(points[0]);
	points[0] = NULL;
	mapc.x = 0;
	mapc.y = 0;
	points = get_loop(map, points, mapc);
	if (!points)
		return (NULL);
	return (points);
}
