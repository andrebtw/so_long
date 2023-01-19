/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:06:10 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/19 16:36:34 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	movement(t_mlx *mlx)
{
	char	*movements;
	char	*coins_left;

	if (mlx->wall_redraw.ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->wall_redraw.ptr);
	mlx->wall_redraw.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./assets/wall.xpm",
		&mlx->wall_redraw.width, &mlx->wall_redraw.height);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->wall_redraw.ptr, 0, 0);
	movements = ft_itoa(mlx->mouvement_count);
	coins_left = ft_itoa(mlx->collectibles_n);
	if (!movements || !coins_left)
		return (ERROR);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 5, 0, 0x00FFFFFF, movements);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 5, 25, 0x00FFFFFF, coins_left);
	free(movements);
	free(coins_left);
	return (0);
}

int	main_loop(t_mlx *mlx)
{
	if (mlx->player.end == 1)
		close_window(mlx);
	if (mlx->loop_count != 1000)
		return (mlx->loop_count++, 0);
	if (mlx->animation.coin.ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->animation.coin.ptr);
	if (mlx->animation.grass.ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->animation.grass.ptr);
	if (mlx->player.xmp.ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->player.xmp.ptr);
	mlx->loop_count = 0;
	if (mlx->frame_count == 9)
		mlx->frame_count = 0;
	if (coin_animation(mlx) == ERROR)
		return (ERROR);
	return (movement(mlx));
}
