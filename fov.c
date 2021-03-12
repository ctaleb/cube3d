/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:07:24 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/10 12:54:57 by ctaleb           ###   ########lyon.fr   */
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
	while (1)
	{
		if (mlx->f->cam_x >= 0)
			mlx->r->e_x = (int)(mlx->r->s_x + 1);
		else if (mlx->r->s_x == mlx->pl->x)
			mlx->r->e_x = (int)(mlx->r->s_x);
		else
			mlx->r->e_x = (int)(mlx->r->s_x - 1);
		mlx->r->e_y = mlx->r->s_y + mlx->f->cam_y
			* ((mlx->r->e_x - mlx->r->s_x) / mlx->f->cam_x);
		mlx->r->s_x = mlx->r->e_x;
		mlx->r->s_y = mlx->r->e_y;
		if (mlx->r->s_x >= mlx->map->max_x || mlx->r->s_y >= mlx->map->max_y
			|| mlx->r->s_x - mlx->r->shift_x < 0 || mlx->r->s_y < 0
			|| mlx->map->grid[(int)mlx->r->s_y]
			[(int)mlx->r->s_x - mlx->r->shift_x] == '1')
			break ;
		// if (mlx->map->grid[(int)mlx->r->s_y]
		// 	[(int)mlx->r->s_x - mlx->r->shift_x] == '2')
		// 	sprite_enable(mlx);
	}
	mlx->r->dist_x = sqrtf(powf(mlx->pl->x - mlx->r->s_x, 2)
			+ powf(mlx->pl->y - mlx->r->s_y, 2));
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
	while (1)
	{
		if (mlx->f->cam_y >= 0)
			mlx->r->e_y = (int)(mlx->r->s_y + 1);
		else if (mlx->r->s_y == mlx->pl->y)
			mlx->r->e_y = (int)(mlx->r->s_y);
		else
			mlx->r->e_y = (int)(mlx->r->s_y - 1);
		mlx->r->e_x = mlx->r->s_x + mlx->f->cam_x
			* ((mlx->r->e_y - mlx->r->s_y) / mlx->f->cam_y);
		mlx->r->s_x = mlx->r->e_x;
		mlx->r->s_y = mlx->r->e_y;
		if (mlx->r->s_x >= mlx->map->max_x || mlx->r->s_y >= mlx->map->max_y
			|| mlx->r->s_x < 0 || mlx->r->s_y - mlx->r->shift_y < 0
			|| mlx->map->grid[(int)mlx->r->s_y - mlx->r->shift_y]
			[(int)mlx->r->s_x] == '1')
			break ;
		// if (mlx->map->grid[(int)mlx->r->s_y]
		// 	[(int)mlx->r->s_x - mlx->r->shift_x] == '2')
		// 	sprite_enable(mlx);
	}
	mlx->r->dist_y = sqrtf(powf(mlx->pl->x - mlx->r->s_x, 2)
			+ powf(mlx->pl->y - mlx->r->s_y, 2));
	if (mlx->r->dist_y < mlx->r->dist_x)
		mlx->r->nwall_x = mlx->r->s_x;
	if (mlx->r->dist_y < mlx->r->dist_x)
		mlx->r->nwall_y = mlx->r->s_y;
}

void	put_rov(float fish, t_mlx_params *mlx)
{
	// float	x;
	// float	y;
	// float	dx;
	// float	dy;
	// float	len;
	// float	i;
	shift_init(mlx);
	step_x_calc(mlx);
	step_y_calc(mlx);
	// if (fabs(mlx->r->nwall_x - mlx->pl->x) >= fabs(mlx->r->nwall_y - mlx->pl->y))
	// 	len = fabs(mlx->r->nwall_x - mlx->pl->x);
	// else
	// 	len = fabs(mlx->r->nwall_y - mlx->pl->y);
	// dx = (mlx->r->nwall_x - mlx->pl->x) / len;
	// dy = (mlx->r->nwall_y - mlx->pl->y) / len;
	// x = mlx->pl->x + 0.0033;
	// y = mlx->pl->y + 0.0033;
	// i = 1;
	//prints one FoV ray on minimap
	// while (i <= len && x < mlx->map->max_x && y < mlx->map->max_y && mlx->map->grid[(int)y][(int)x] != '1')
	// {
	// 	my_mlx_pixel_put(mlx, x * mlx->map->ratio, y * mlx->map->ratio, rgbtoi(0, 255, 0, 255));
	// 	x = x + (dx / mlx->map->ratio);
	// 	y = y + (dy / mlx->map->ratio);
	// 	i = i + (1 / mlx->map->ratio);
	// }
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
		ray += nb_ray;
		mlx->r->id++;
	}
	mlx->f->cam_x = cam_x;
	mlx->f->cam_y = cam_y;
}
