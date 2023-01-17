/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:33:05 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/17 13:25:17 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	draw_frame_loop(t_mlx *mlx, t_map mapc, t_map coords, t_xmp *grass)
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
					grass->ptr, coords.x, coords.y);
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					mlx->animation.coin.ptr, coords.x, coords.y);
			}
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
	t_xmp	grass;

	coords.x = 0;
	coords.y = 0;
	mapc.y = 0;
	mlx->animation.coin.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, location,
			&mlx->animation.coin.width, &mlx->animation.coin.height);
	grass.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./assets/grass.xpm",
		&grass.width, &grass.height);
	if (!mlx->animation.coin.ptr || !grass.ptr)
		return (ERROR);
	draw_frame_loop(mlx, mapc, coords, &grass);
	return (0);
}

int	coin_animation(t_mlx *mlx)
{
	char	*location;

	if (mlx->loop_count != 1000)
	{
		return (mlx->loop_count++, 0);
	}
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
	return (0);
}
