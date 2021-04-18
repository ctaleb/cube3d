/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:48:07 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/17 16:51:06 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	put_health(t_mlx_params *mlx, int x, int y)
{
	int	x_max;
	int	y_max;
	int	var_x;

	x_max = x - 5 - 100 + mlx->pl->health;
	y_max = y - 5;
	y -= 20;
	while (y < y_max)
	{
		var_x = x - 105;
		while (var_x < x_max)
		{
			my_mlx_pixel_put(mlx, var_x, y, rgbtoi(0, 250, 0, 0));
			var_x++;
		}
		y++;
	}
}

static void	sky_painter(t_mlx_params *mlx)
{
	int	tex_x;
	int	tex_y;
	int	x;
	int	y;

	y = 0;
	while (y < mlx->map->res_y / 2)
	{
		x = 0;
		while (x < mlx->map->res_x)
		{
			tex_x = x * (mlx->skybox->width / 4) / mlx->map->res_x
				+ (mlx->skybox->width * mlx->f->angle / 360);
			tex_y = y * (mlx->skybox->height / 3) / mlx->map->res_y
				+ mlx->skybox->height / 3;
			if (mlx->skybox->addr[tex_y * mlx->skybox->width + tex_x])
				my_mlx_pixel_put(mlx, x, y, mlx->skybox->addr[tex_y
					* mlx->skybox->width + tex_x]);
			x++;
		}
		y++;
	}
}

void	put_sky(t_mlx_params *mlx)
{
	if (!mlx->defined->skybox)
		return ;
	mlx->f->angle = rad_deg(atan(mlx->f->cam_y / mlx->f->cam_x));
	if (mlx->f->cam_x > 0 && mlx->f->cam_y < 0)
		mlx->f->angle += 360;
	if (mlx->f->cam_x < 0 && mlx->f->cam_y < 0)
		mlx->f->angle += 180;
	if (mlx->f->cam_x < 0 && mlx->f->cam_y > 0)
		mlx->f->angle += 180;
	sky_painter(mlx);
}

void	put_healthbar(t_mlx_params *mlx)
{
	int	tex_x;
	int	tex_y;
	int	x;
	int	y;

	if (!mlx->defined->healthbar)
		return ;
	tex_x = 0;
	tex_y = 0;
	y = (mlx->map->res_y / 4 * 3) - mlx->healthbar->height / 2;
	while (tex_y < mlx->healthbar->height)
	{
		x = mlx->map->res_x / 4 - mlx->healthbar->width / 2;
		tex_x = 0;
		while (tex_x < mlx->healthbar->width)
		{
			my_mlx_pixel_put(mlx, x, y, mlx->healthbar->addr[tex_y * mlx->healthbar->width + tex_x]);
			tex_x++;
			x++;
		}
		tex_y++;
		y++;
	}
	put_health(mlx, x, y);
}
