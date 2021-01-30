/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:41:46 by ctaleb            #+#    #+#             */
/*   Updated: 2021/01/28 11:27:55 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	put_camera(t_mlx_params *mlx)
{
	int x;
	int y;
	int colour;

	colour = rgbtoi(0, 0, 153, 73);
	x = (mlx->pl->cam_x + mlx->pl->x) * 10;
	y = (mlx->pl->cam_y + mlx->pl->y) * 10;
	mlx_pixel_put(mlx->ptr, mlx->win, x, y, colour);
	mlx_pixel_put(mlx->ptr, mlx->win, x - 1, y, colour);
	mlx_pixel_put(mlx->ptr, mlx->win, x, y - 1, colour);
	mlx_pixel_put(mlx->ptr, mlx->win, x - 1, y - 1, colour);
}

void	rem_camera(t_mlx_params *mlx)
{
	int x;
	int y;

	x = (mlx->pl->cam_x + mlx->pl->x)* 10;
	y = (mlx->pl->cam_y + mlx->pl->y) * 10;
	put_map(x, y, mlx);
	put_map(x - 1, y, mlx);
	put_map(x, y - 1, mlx);
	put_map(x - 1, y - 1, mlx);
}
