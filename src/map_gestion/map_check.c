/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:26:58 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/05 12:36:29 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	check_characters(char **map, char *allowed_characters)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr(allowed_characters, map[y][x]) == NULL)
			{
				error_printing("Illegal characters found on your map file.",
					"Make sure your file only has '01CEP'",
					"\n\n111111\n1PCCE1\n111111");
				return (ERROR);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	map_check(char **map)
{
	char	*allowed_characters;

	allowed_characters = ft_strdup("01CEP\n");
	if (check_characters(map, allowed_characters) == ERROR)
		return (free(allowed_characters), ERROR);
	return (free(allowed_characters), 0);
}
