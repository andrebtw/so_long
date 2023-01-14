/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:09:21 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/14 15:27:03 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"


t_mlx create_window(t_mlx mlx)
{
	t_xmp	grass;
	t_image	image;
	
	image.img = mlx_new_image(mlx.mlx_ptr, 1920, 1080);
	grass.ptr = mlx_xpm_file_to_image(mlx.mlx_ptr, "./grass.xpm", &grass.width, &grass.height);
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
	{
		tab_free(mlx.map);
		exit(0);
	}
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1920, 1080, "so_long");
	mlx_hook(mlx.win_ptr, 17, 1L<<5, close_window, &mlx);
	mlx_hook(mlx.win_ptr, 2, 1L<<0, close_window_esc, &mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, grass.ptr, 0, 0);
	mlx_loop(mlx.mlx_ptr);
	return (mlx);
}
