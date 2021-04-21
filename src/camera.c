/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:41:46 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/03 13:57:00 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	put_camera(t_mlx_params *mlx)
{
	int	x;
	int	y;
	int	colour;

	colour = rgbtoi(0, 0, 153, 73);
	x = (mlx->f->cam_x + mlx->pl->x) * mlx->map->ratio;
	y = (mlx->f->cam_y + mlx->pl->y) * mlx->map->ratio;
	my_mlx_pixel_put(mlx, x, y, colour);
	my_mlx_pixel_put(mlx, x - 1, y, colour);
	my_mlx_pixel_put(mlx, x, y - 1, colour);
	my_mlx_pixel_put(mlx, x - 1, y - 1, colour);
}

void	rem_camera(t_mlx_params *mlx)
{
	int	x;
	int	y;

	x = (mlx->f->cam_x + mlx->pl->x) * mlx->map->ratio;
	y = (mlx->f->cam_y + mlx->pl->y) * mlx->map->ratio;
	put_map(x, y, mlx);
	put_map(x - 1, y, mlx);
	put_map(x, y - 1, mlx);
	put_map(x - 1, y - 1, mlx);
}
