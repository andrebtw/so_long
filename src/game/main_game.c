/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:38:55 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/30 11:38:55 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	main_game(char *file)
{
	char	**map;
	int y = 0;
	map = map_opening(file);
	if (!map)
		return (ERROR);
	ft_printf("%s", map[y]);
	return (0);
}
