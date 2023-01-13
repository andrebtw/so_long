/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:38:55 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/13 14:31:43 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"


int	main_game(char *file)
{
	char	**map;
	t_mlx	mlx;

	map = map_opening(file);
	if (!map)
		return (ERROR);
	if (map_check(map, file) == ERROR)
		return (tab_free(map), ERROR);
	mlx = create_window(map);
	if (!mlx.mlx_ptr)
		return (ERROR);
	return (tab_free(map), 0);
}
