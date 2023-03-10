/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:27:19 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/23 18:28:12 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	re_render(t_mlx *mlx, int y, int x)
{
	if (ft_strchr("C", mlx->map[mlx->player.y][mlx->player.x]))
		mlx->map[mlx->player.y][mlx->player.x] = '0';
	mlx->player.xmp.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./assets/player1.xpm",
			&mlx->player.xmp.width, &mlx->player.xmp.height);
	if (!mlx->player.xmp.ptr)
		return (error_message(), close_window(mlx));
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->player.xmp.ptr, mlx->player.x * 50, mlx->player.y * 50);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->grass_redraw.ptr, (mlx->player.x + x) * 50,
		(mlx->player.y + y) * 50);
	return (2);
}

int	player(int keycode, t_mlx *mlx)
{
	if (mlx->player.xmp.ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->player.xmp.ptr);
	if (mlx->grass_redraw.ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->grass_redraw.ptr);
	mlx->grass_redraw.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./assets/grass.xpm",
			&mlx->grass_redraw.width, &mlx->grass_redraw.height);
	if (!mlx->grass_redraw.ptr)
		return (ERROR, close_window(mlx));
	if (keycode == ESC_KEY)
		return (close_window(mlx));
	if (keycode == W_KEY)
		if (player_up(mlx) == 2)
			mlx->mouvement_count++;
	if (keycode == S_KEY)
		if (player_down(mlx) == 2)
			mlx->mouvement_count++;
	if (keycode == A_KEY)
		if (player_left(mlx) == 2)
			mlx->mouvement_count++;
	if (keycode == D_KEY)
		if (player_right(mlx) == 2)
			mlx->mouvement_count++;
	mlx->player.xmp.ptr = NULL;
	return (0);
}
