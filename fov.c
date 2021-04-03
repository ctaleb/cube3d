/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:07:24 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/03 14:21:17 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	shift_init(t_mlx_params *mlx)
{
	if (mlx->f->cam_x >= 0)
		mlx->r->shift_x = 0;
	else
		mlx->r->shift_x = 1;
	if (mlx->f->cam_y >= 0)
		mlx->r->shift_y = 0;
	else
		mlx->r->shift_y = 1;
}

static void	step_x_calc(t_mlx_params *mlx)
{
	mlx->r->s_x = mlx->pl->x;
	mlx->r->s_y = mlx->pl->y;
	mlx->r->dist_x = 0;
	if (mlx->f->cam_x == 0)
		return ;
	find_y(mlx);
	while (is_valid_coord(mlx->r->shift_x, 0, mlx))
	{
		mlx->r->s_x += mlx->r->n_x;
		mlx->r->s_y += mlx->r->n_y;
	}
	mlx->r->dist_x = ft_dist(mlx->r->s_x, mlx->r->s_y, mlx->pl->x, mlx->pl->y);
	mlx->r->nwall_x = mlx->r->s_x;
	mlx->r->nwall_y = mlx->r->s_y;
}

static void	step_y_calc(t_mlx_params *mlx)
{
	mlx->r->s_x = mlx->pl->x;
	mlx->r->s_y = mlx->pl->y;
	mlx->r->dist_y = 0;
	if (mlx->f->cam_y == 0)
		return ;
	find_x(mlx);
	while (is_valid_coord(0, mlx->r->shift_y, mlx))
	{
		mlx->r->s_x += mlx->r->n_x;
		mlx->r->s_y += mlx->r->n_y;
	}
	mlx->r->dist_y = ft_dist(mlx->r->s_x, mlx->r->s_y, mlx->pl->x, mlx->pl->y);
	if (mlx->r->dist_y < mlx->r->dist_x)
		mlx->r->nwall_x = mlx->r->s_x;
	if (mlx->r->dist_y < mlx->r->dist_x)
		mlx->r->nwall_y = mlx->r->s_y;
}

void	put_rov(float fish, t_mlx_params *mlx)
{
	shift_init(mlx);
	step_x_calc(mlx);
	step_y_calc(mlx);
	ray_cannon(fish, mlx);
}

void	put_fov(t_mlx_params *mlx)
{
	float	ray;
	float	nb_ray;
	float	cam_x;
	float	cam_y;

	ray = -mlx->f->fov;
	nb_ray = ((float)mlx->f->fov * 2) / ((float)mlx->map->res_x);
	cam_x = mlx->f->cam_x;
	cam_y = mlx->f->cam_y;
	mlx->r->id = 0;
	while (ray <= mlx->f->fov && mlx->r->id < mlx->map->res_x)
	{	
		mlx->f->cam_x = cam_x * cos(0.01745 * ray) - cam_y * sin(0.01745 * ray);
		mlx->f->cam_y = cam_x * sin(0.01745 * ray) + cam_y * cos(0.01745 * ray);
		put_rov(cos(0.01745 * ray), mlx);
		ray += nb_ray * mlx->f->multi;
		mlx->r->id += mlx->f->multi;
	}
	mlx->f->cam_x = cam_x;
	mlx->f->cam_y = cam_y;
}
