/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:09:21 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/14 14:05:21 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_mlx create_window(t_mlx mlx)
{
	//t_image	grass;

	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
	{
		tab_free(mlx.map);
		exit(0);
	}
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1920, 1080, "so_long");
	//grass.ptr = mlx_xpm_file_to_image(mlx.mlx_ptr, ".../assets/grass.xpm", &grass.width, &grass.height);
	mlx_hook(mlx.win_ptr, 17, 1L<<5, close_window, &mlx);
	mlx_hook(mlx.win_ptr, 2, 1L<<0, close_window_esc, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (mlx);
}
