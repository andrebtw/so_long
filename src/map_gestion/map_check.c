/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:26:58 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/07 16:28:58 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

typedef struct s_map_points
{
	int	e;
	int	c;
	int	p;
}	t_map_points;

int	check_doubles_message(t_map_points mapp)
{
	if (mapp.e != 1)
	{
		error_printing("The map doesn't have 1 exit.",
			"Make sure to have an exit, only 1.",
			"\n\n111111\n1PCCE1\n111111");
		return (ERROR);
	}
	if (mapp.p != 1)
	{
		error_printing("The map doesn't have 1 starting position.",
			"Make sure to have a starting position, only 1.",
			"\n\n111111\n1PCCE1\n111111");
		return (ERROR);
	}
	if (mapp.c < 1)
	{
		error_printing("The map doesn't have at least 1 edible.",
			"Make sure to have a starting position, only 1.",
			"\n\n111111\n1PCCE1\n111111");
		return (ERROR);
	}
	return (0);
}

int	check_doubles(char **map)
{
	t_map			mapc;
	t_map_points	mapp;

	mapc.y = 0;
	mapp.c = 0;
	mapp.e = 0;
	mapp.p = 0;
	while (map[mapc.y])
	{
		mapc.x = 0;
		while (map[mapc.y][mapc.x])
		{
			if (map[mapc.y][mapc.x] == 'C')
				mapp.c++;
			if (map[mapc.y][mapc.x] == 'E')
				mapp.e++;
			if (map[mapc.y][mapc.x] == 'P')
				mapp.p++;
			mapc.x++;
		}
		mapc.y++;
	}
	return (check_doubles_message(mapp));
}

int	check_characters(char **map, char *allowed_characters)
{
	t_map	mapc;

	mapc.y = 0;
	while (map[mapc.y])
	{
		mapc.x = 0;
		while (map[mapc.y][mapc.x])
		{
			if (ft_strchr(allowed_characters, map[mapc.y][mapc.x]) == NULL)
			{
				error_printing("Illegal characters found on your map file.",
					"Make sure your file only has '01CEP'",
					"\n\n111111\n1PCCE1\n111111");
				return (ERROR);
			}
			mapc.x++;
		}
		mapc.y++;
	}
	return (check_doubles(map));
}

int	map_check(char **map)
{
	char	*allowed_characters;

	allowed_characters = ft_strdup("01CEP\n");
	if (check_characters(map, allowed_characters) == ERROR)
		return (free(allowed_characters), ERROR);
	if (check_if_rectangular(map) == ERROR || check_walls(map) == ERROR)
		return (free(allowed_characters), ERROR);
	return (free(allowed_characters), 0);
}
