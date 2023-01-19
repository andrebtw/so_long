/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:27:19 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/19 16:36:48 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	re_render(t_mlx *mlx, int y, int x)
{
	if (ft_strchr("C", mlx->map[mlx->player.y][mlx->player.x]))
		mlx->map[mlx->player.y][mlx->player.x] = '0';
	mlx->player.xmp.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./assets/player1.xpm",
		&mlx->player.xmp.width, &mlx->player.xmp.height);
	if (!mlx->player.xmp.ptr)
		return (ERROR);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->player.xmp.ptr, mlx->player.x * 50, mlx->player.y * 50);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->grass_redraw.ptr, (mlx->player.x + x) * 50, (mlx->player.y + y) * 50);
	return (0);
}

int	player_down(t_mlx *mlx)
{
	if (ft_strchr("E", (mlx->map[mlx->player.y + 1][mlx->player.x])) && !mlx->collectibles_n)
		mlx->player.end = 1;
	if (ft_strchr("0PC", (mlx->map[mlx->player.y + 1][mlx->player.x])))
	{
		mlx->player.y = mlx->player.y + 1;
		if (mlx->map[mlx->player.y][mlx->player.x] == 'C')
			mlx->collectibles_n--;
		return (re_render(mlx, -1, 0));
	}
	mlx->player.xmp.ptr = NULL;
	return (0);
}

int	player_left(t_mlx *mlx)
{
	if (ft_strchr("E", (mlx->map[mlx->player.y][mlx->player.x - 1])) && !mlx->collectibles_n)
			mlx->player.end = 1;
	if (ft_strchr("0PC", (mlx->map[mlx->player.y][mlx->player.x - 1])))
	{
		mlx->player.x = mlx->player.x - 1;
		if (mlx->map[mlx->player.y][mlx->player.x] == 'C')
			mlx->collectibles_n--;
		return (re_render(mlx, 0, 1));
	}
	mlx->player.xmp.ptr = NULL;
	return (0);
}

int	player_right(t_mlx *mlx)
{
	if (ft_strchr("E", (mlx->map[mlx->player.y][mlx->player.x + 1])) && !mlx->collectibles_n)
		mlx->player.end = 1;
	if (ft_strchr("0PC", mlx->map[mlx->player.y][mlx->player.x + 1]))
	{
		mlx->player.x = mlx->player.x + 1;
		if (mlx->map[mlx->player.y][mlx->player.x] == 'C')
			mlx->collectibles_n--;
		return (re_render(mlx, 0, -1));
	}
	mlx->player.xmp.ptr = NULL;
	return (0);
}

int	player_up(t_mlx *mlx)
{
	if (ft_strchr("E", (mlx->map[mlx->player.y - 1][mlx->player.x])) && !mlx->collectibles_n)
		mlx->player.end = 1;
	if (ft_strchr("0PC", (mlx->map[mlx->player.y - 1][mlx->player.x])))
	{
		mlx->player.y = mlx->player.y - 1;
		if (mlx->map[mlx->player.y][mlx->player.x] == 'C')
			mlx->collectibles_n--;
		return (re_render(mlx, 1, 0));
	}
	mlx->player.xmp.ptr = NULL;
	return (0);
}

int	player(int keycode, t_mlx *mlx)
{
	if (mlx->player.xmp.ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->player.xmp.ptr);
	if (mlx->grass_redraw.ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->grass_redraw.ptr);
	mlx->grass_redraw.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./assets/grass.xpm",
			&mlx->grass_redraw.width, &mlx->grass_redraw.height);
	if (!mlx->grass_redraw.ptr)
		return (ERROR);
	if (keycode == ESC_KEY)
		return (close_window(mlx));
	mlx->mouvement_count++;
	if (keycode == W_KEY)
		return (player_up(mlx));
	if (keycode == S_KEY)
		return (player_down(mlx));
	if (keycode == A_KEY)
		return (player_left(mlx));
	if (keycode == D_KEY)
		return (player_right(mlx));
	mlx->player.xmp.ptr = NULL;
	return (0);
}
