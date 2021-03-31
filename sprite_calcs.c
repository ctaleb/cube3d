/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_calcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:41:06 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/31 16:55:15 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	sprite_dist(t_mlx_params *mlx)
{
	int		i;
	float	x;
	float	y;

	i = 0;
	while (i < mlx->map->sprite_nb)
	{
		x = mlx->sp[i]->x;
		y = mlx->sp[i]->y;
		mlx->sp[i]->dist = sqrtf(powf(x - mlx->pl->x, 2)
				+ powf(y - mlx->pl->y, 2));
		i++;
	}
}

void	sprite_sizer(int i, t_mlx_params *mlx)
{
	int		ray_height;
	int		size;
	float	fish_dist;
	float	ray;

	ray = -mlx->f->fov + (((float)mlx->f->fov * 2)
			/ ((float)mlx->map->res_x))
		* ((float)mlx->map->res_x / 2 + mlx->sp[i]->r_x);
	fish_dist = mlx->sp[i]->dist * cos(deg_rad(1) * ray);
	ray_height = (int)(mlx->map->res_y / fish_dist);
	mlx->sp[i]->u_coord = - ((float)ray_height) / 2
		+ (float)mlx->map->res_y / 2 - 2;
	mlx->sp[i]->b_coord = (float)ray_height / 2
		+ (float)mlx->map->res_y / 2 + 2;
	size = mlx->sp[i]->b_coord - mlx->sp[i]->u_coord;
	mlx->sp[i]->l_coord = (float)mlx->map->res_x / 2
		+ mlx->sp[i]->r_x - size / 2;
	mlx->sp[i]->r_coord = (float)mlx->map->res_x / 2
		+ mlx->sp[i]->r_x + size / 2;
}


void	sprite_disable(int i, t_mlx_params *mlx)
{
	if (mlx->sp[i]->angle + 0.2 < -mlx->f->fov * 0.0174533
		|| mlx->sp[i]->angle - 0.2 > mlx->f->fov * 0.0174533)
		mlx->sp[i]->visible = 0;
}
