/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:57:37 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/04 13:34:51 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	put_sky(t_mlx_params *mlx)
{
	int	tex_x;
	int	tex_y;
	int	x;
	int	y;

	mlx->f->angle = rad_deg(atan(mlx->f->cam_y / mlx->f->cam_x));
	if (mlx->f->cam_x > 0 && mlx->f->cam_y < 0)
		mlx->f->angle += 360;
	if (mlx->f->cam_x < 0 && mlx->f->cam_y < 0)
		mlx->f->angle += 180;
	if (mlx->f->cam_x < 0 && mlx->f->cam_y > 0)
		mlx->f->angle += 180;

	y = 0;
	while (y < mlx->map->res_y / 2)
	{
		x = 0;
		while (x < mlx->map->res_x)
		{
			tex_x = x * (mlx->skybox->width / 4) / mlx->map->res_x + (mlx->skybox->width * mlx->f->angle / 360);
			tex_y = y * (mlx->skybox->height / 3) / mlx->map->res_y + mlx->skybox->height / 3;
			if (mlx->skybox->addr[tex_y * mlx->skybox->width + tex_x])
				my_mlx_pixel_put(mlx, x, y, mlx->skybox->addr[tex_y * mlx->skybox->width + tex_x]);
			x++;
		}
		y++;
	}
}