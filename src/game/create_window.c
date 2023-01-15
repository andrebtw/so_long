/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:09:21 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/15 15:10:26 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"
/*
int	draw_tiles(t_mlx *mlx)
{
	t_xmp	grass;
	t_xmp	wall;

	grass.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./assets/grass.xpm", &grass.width, &grass.height);
	wall.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./assets/grass.xpm", &wall.width, &wall.height);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, ptr, 0, 0);
	return (0);
}*/

int	create_window(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
	{
		ft_printf("EXIT");
		tab_free(mlx->map);
		exit(0);
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1920, 1080, "so_long");
	if (!mlx->win_ptr)
	{
		ft_printf("SUCK BALLS");
	}
	mlx_hook(mlx->win_ptr, 17, 1L<<5, close_window, &(*mlx));
	mlx_hook(mlx->win_ptr, 2, 1L<<0, close_window_esc, &(*mlx));
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
