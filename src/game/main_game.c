/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:38:55 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/15 13:56:42 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"


int	main_game(char *file)
{
	t_mlx	mlx;

	mlx.map = map_opening(file);
	if (!mlx.map)
		return (ERROR);
	if (map_check(mlx.map, file) == ERROR)
		return (tab_free(mlx.map), ERROR);
	create_window(&mlx);
	if (!mlx.mlx_ptr)
		return (ERROR);
	return (tab_free(mlx.map), 0);
}
