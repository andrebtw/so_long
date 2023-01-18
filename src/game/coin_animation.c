/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:33:05 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/18 23:19:26 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	draw_frame_loop(t_mlx *mlx, t_map mapc, t_map coords)
{
	while (mlx->map[mapc.y])
	{
		mapc.x = -1;
		coords.x = 0;
		while (mlx->map[mapc.y][++mapc.x])
		{
			if (ft_strchr("C", mlx->map[mapc.y][mapc.x]))
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					mlx->animation.grass.ptr, coords.x, coords.y);
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					mlx->animation.coin.ptr, coords.x, coords.y);
			}
			if (ft_strchr("0", mlx->map[mapc.y][mapc.x]))
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					mlx->animation.grass.ptr, coords.x, coords.y);
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
				mlx->player.xmp.ptr, mlx->player.x * 50, mlx->player.y * 50);
			coords.x = coords.x + 50;
		}
		mapc.y++;
		coords.y = coords.y + 50;
	}
}

int	draw_frame(t_mlx *mlx, char *location)
{
	t_map	mapc;
	t_map	coords;

	coords.x = 0;
	coords.y = 0;
	mapc.y = 0;
	mlx->animation.coin.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, location,
			&mlx->animation.coin.width, &mlx->animation.coin.height);
	mlx->animation.grass.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./assets/grass.xpm",
		&mlx->animation.grass.width, &mlx->animation.grass.height);
	mlx->player.xmp.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./assets/player1.xpm",
			&mlx->player.xmp.width, &mlx->player.xmp.height);
	if (!mlx->animation.coin.ptr || !mlx->animation.grass.ptr)
		return (ERROR);
	if (!mlx->player.xmp.ptr)
		return (ERROR);
	draw_frame_loop(mlx, mapc, coords);
	return (0);
}

int	coin_animation(t_mlx *mlx)
{
	char	*location;

	if (mlx->player.end == 1)
		close_window(mlx);
	if (mlx->loop_count != 1000)
	{
		return (mlx->loop_count++, 0);
	}
	if (mlx->animation.coin.ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->animation.coin.ptr);
	if (mlx->animation.grass.ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->animation.grass.ptr);
	if (mlx->player.xmp.ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->player.xmp.ptr);
	mlx->loop_count = 0;
	if (mlx->frame_count == 9)
		mlx->frame_count = 0;
	location = ft_strdup("./assets/coins/");
	if (!location)
		return (ERROR);
	location = ft_strjoin_free(location, ft_itoa(mlx->frame_count), 1, 1);
	if (!location)
		return (ERROR);
	location = ft_strjoin_free(location, ".xpm", 1, 0);
	if (!location)
		return (ERROR);
	if (draw_frame(mlx, location) == ERROR)
		return (ERROR);
	mlx->frame_count++;
	free(location);
	return (0);
}
