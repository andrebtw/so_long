/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window_funcs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:05:10 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/14 14:44:25 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	close_window(t_mlx *mlx)
{
	tab_free(mlx->map);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(0);
	return (0);
}

int	close_window_esc(int keycode, t_mlx *mlx)
{
	if (keycode != 53)
		return (0);
	tab_free(mlx->map);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(0);
}
