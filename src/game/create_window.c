/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:09:21 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/13 17:07:57 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	close_window(t_mlx mlx)
{
	mlx_destroy_image(mlx.mlx_ptr, mlx.win_ptr);
	return (0);
}

t_mlx create_window(char **map)
{
	t_mlx	mlx;
	t_image	grass;

	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
	{
		//tab_free(map);
		exit(0);
	}
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1920, 1080, "so_long");
	grass.ptr = mlx_xpm_file_to_image(mlx.mlx_ptr, ".../assets/grass.xpm", &grass.width, &grass.height);
	mlx_hook(mlx.win_ptr, 17, 0, close_window, &mlx);
	mlx_loop(mlx.mlx_ptr);
	free(mlx.mlx_ptr);
	return (mlx);
}
