/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:27:19 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/18 23:25:14 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	player_down(t_mlx *mlx)
{
	if (ft_strchr("E", (mlx->map[mlx->player.y + 1][mlx->player.x]) && mlx->collectibles_n == 0))
		ft_printf("%s",ft_strchr("E", (mlx->map[mlx->player.y + 1][mlx->player.x])));
	if (ft_strchr("0PC", (mlx->map[mlx->player.y + 1][mlx->player.x])))
	{
		mlx->player.y = mlx->player.y + 1;
		if (ft_strchr("C", mlx->map[mlx->player.y][mlx->player.x]))
			mlx->map[mlx->player.y][mlx->player.x] = '0';
		mlx->player.xmp.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./assets/player1.xpm",
			&mlx->player.xmp.width, &mlx->player.xmp.height);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
				mlx->player.xmp.ptr, mlx->player.x * 50, mlx->player.y * 50);
		mlx->collectibles_n--;
		return (0);
	}
	mlx->player.xmp.ptr = NULL;
	return (0);
}

int	player_left(t_mlx *mlx)
{
	if (ft_strchr("E", (mlx->map[mlx->player.y][mlx->player.x - 1]) && mlx->collectibles_n == 0))
			mlx->player.end = 1;
	if (ft_strchr("0PC", (mlx->map[mlx->player.y][mlx->player.x - 1])))
	{
		mlx->player.x = mlx->player.x - 1;
		if (ft_strchr("C", mlx->map[mlx->player.y][mlx->player.x]))
			mlx->map[mlx->player.y][mlx->player.x] = '0';
		mlx->player.xmp.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./assets/player1.xpm",
			&mlx->player.xmp.width, &mlx->player.xmp.height);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
				mlx->player.xmp.ptr, mlx->player.x * 50, mlx->player.y * 50);
		mlx->collectibles_n--;
		return (0);
	}
	mlx->player.xmp.ptr = NULL;
	return (0);
}

int	player_right(t_mlx *mlx)
{
	if (ft_strchr("E", (mlx->map[mlx->player.y][mlx->player.x + 1]) && mlx->collectibles_n == 0))
		mlx->player.end = 1;
	if (ft_strchr("0PC", mlx->map[mlx->player.y][mlx->player.x + 1]))
	{
		mlx->player.x = mlx->player.x + 1;
		if (ft_strchr("C", mlx->map[mlx->player.y][mlx->player.x]))
			mlx->map[mlx->player.y][mlx->player.x] = '0';
		mlx->player.xmp.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./assets/player1.xpm",
			&mlx->player.xmp.width, &mlx->player.xmp.height);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
				mlx->player.xmp.ptr, mlx->player.x * 50, mlx->player.y * 50);
		mlx->collectibles_n--;
		return (0);
	}
	mlx->player.xmp.ptr = NULL;
	return (0);
}

int	player_up(t_mlx *mlx)
{
	if (ft_strchr("E", (mlx->map[mlx->player.y - 1][mlx->player.x]) && mlx->collectibles_n == 0))
		mlx->player.end = 1;
	if (ft_strchr("0PC", (mlx->map[mlx->player.y - 1][mlx->player.x])))
	{
		mlx->player.y = mlx->player.y - 1;
		if (ft_strchr("C", mlx->map[mlx->player.y][mlx->player.x]))
			mlx->map[mlx->player.y][mlx->player.x] = '0';
		mlx->player.xmp.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./assets/player1.xpm",
			&mlx->player.xmp.width, &mlx->player.xmp.height);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
				mlx->player.xmp.ptr, mlx->player.x * 50, mlx->player.y * 50);
		mlx->collectibles_n--;
		return (0);
	}
	mlx->player.xmp.ptr = NULL;
	return (0);
}

int	player(int keycode, t_mlx *mlx)
{
	if (mlx->player.xmp.ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->player.xmp.ptr);
	if (keycode == ESC_KEY)
		return (close_window(mlx));
	if (keycode == W_KEY)
		return (player_up(mlx));
	if (keycode == S_KEY)
		return (player_down(mlx));
	if (keycode == A_KEY)
		return (player_left(mlx));
	if (keycode == D_KEY)
		return (player_right(mlx));
	return (0);
}
