/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:07:24 by ctaleb            #+#    #+#             */
/*   Updated: 2021/02/13 16:56:34 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	step_x_calc(t_mlx_params *mlx)
{
	float	s_x;
	float	s_y;
	float	x;
	float	y;

	s_x = mlx->pl->x;
	s_y = mlx->pl->y;
	mlx->pl->dist_x = 0;
	if (mlx->pl->cam_x == 0)
		return ;
	while (s_x < mlx->map->max_x && s_y < mlx->map->max_y &&
	s_x >= 0 && s_y >= 0 && mlx->map->grid[(int)s_y][(int)s_x] != '1')
	{
		if (mlx->pl->cam_x >= 0)
			x = (int)(s_x + 1);
		else if (s_x == mlx->pl->x)
			x = (int)(s_x);
		else
			x = (int)(s_x - 1);
		y = s_y + mlx->pl->cam_y * ((x - s_x) / mlx->pl->cam_x);
		mlx->pl->dist_x += sqrt(exp2(fabs(s_x - x)) + exp2(fabs(s_y - y)));
		s_x = x;
		s_y = y;
	}
	mlx->pl->nwall_x = s_x;
	mlx->pl->nwall_y = s_y;
}

static void	step_y_calc(t_mlx_params *mlx)
{
	float	s_x;
	float	s_y;
	float	x;
	float	y;

	s_x = mlx->pl->x;
	s_y = mlx->pl->y;
	mlx->pl->dist_y = 0;
	if (mlx->pl->cam_y == 0)
		return ;
	while (s_x < mlx->map->max_x && s_y < mlx->map->max_y &&
	s_x >= 0 && s_y >= 0 && mlx->map->grid[(int)s_y][(int)s_x] != '1')
	{
		if (mlx->pl->cam_y >= 0)
			y = (int)(s_y + 1);
		else if (s_y == mlx->pl->y)
			y = (int)(s_y);
		else
			y = (int)(s_y - 1);
		x = s_x + mlx->pl->cam_x * ((y - s_y) / mlx->pl->cam_y);
		mlx->pl->dist_y += sqrt(exp2(fabs(s_y - y)) + exp2(fabs(s_x - x)));
		s_x = x;
		s_y = y;
	}
	if (mlx->pl->dist_y < mlx->pl->dist_x)
		mlx->pl->nwall_x = s_x;
	if (mlx->pl->dist_y < mlx->pl->dist_x)
		mlx->pl->nwall_y = s_y;
}

void	put_rov(t_mlx_params *mlx)
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	len;
	float	i;

	step_x_calc(mlx);
	step_y_calc(mlx);
	if (fabs(mlx->pl->nwall_x - mlx->pl->x) >= fabs(mlx->pl->nwall_y - mlx->pl->y))
		len = fabs(mlx->pl->nwall_x - mlx->pl->x);
	else
		len = fabs(mlx->pl->nwall_y - mlx->pl->y);
	dx = (mlx->pl->nwall_x - mlx->pl->x) / len;
	dy = (mlx->pl->nwall_y - mlx->pl->y) / len;
	x = mlx->pl->x + 0.0033;
	y = mlx->pl->y + 0.0033;
	i = 1;
	printf("len%f\tdistx%f\tdisty%f\ndx%f\tdy%f\n", len, mlx->pl->dist_x, mlx->pl->dist_y, dx, dy);
	while (i <= len && x < mlx->map->max_x && y < mlx->map->max_y && mlx->map->grid[(int)y][(int)x] != '1')
	{
		mlx_pixel_put(mlx->ptr, mlx->win, x * mlx->map->ratio, y * mlx->map->ratio, rgbtoi(0, 255, 0, 255));
		x = x + (dx / mlx->map->ratio);
		y = y + (dy / mlx->map->ratio);
		i = i + (1 / mlx->map->ratio);
	}
}

void	put_fov(t_mlx_params *mlx)
{
	int		ray;
	float	cam_x;
	float	cam_y;

	ray = -30;
	cam_x = mlx->pl->cam_x;
	cam_y = mlx->pl->cam_y;
	while (ray <= mlx->pl->fov)
	{	
		mlx->pl->cam_x = cam_x * cos(0.01745 * ray) - cam_y * sin(0.01745 * ray);
		mlx->pl->cam_y = cam_x * sin(0.01745 * ray) + cam_y * cos(0.01745 * ray);
		put_rov(mlx);
		ray += 1;
	}
	mlx->pl->cam_x = cam_x;
	mlx->pl->cam_y = cam_y;
}