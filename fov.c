/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:07:24 by ctaleb            #+#    #+#             */
/*   Updated: 2021/02/25 13:05:01 by ctaleb           ###   ########lyon.fr   */
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
	float	s_x;
	float	s_y;
	float	x;
	float	y;

	s_x = mlx->pl->x;
	s_y = mlx->pl->y;
	mlx->r->dist_x = 0;
	if (mlx->f->cam_x == 0)
		return ;
	while (1)
	{
		if (mlx->f->cam_x >= 0)
			x = (int)(s_x + 1);
		else if (s_x == mlx->pl->x)
			x = (int)(s_x);
		else
			x = (int)(s_x - 1);
		y = s_y + mlx->f->cam_y * ((x - s_x) / mlx->f->cam_x);
		s_x = x;
		s_y = y;
		if (s_x >= mlx->map->max_x || s_y >= mlx->map->max_y ||
		s_x - mlx->r->shift_x < 0 || s_y < 0 || mlx->map->grid[(int)s_y][(int)s_x - mlx->r->shift_x] == '1')
			break ;
	}
	mlx->r->dist_x = sqrtf(powf(mlx->pl->x - s_x, 2) + powf(mlx->pl->y - s_y, 2));
	// printf("distx%f\n", mlx->r->dist_x);
	mlx->r->nwall_x = s_x;
	mlx->r->nwall_y = s_y;
}

static void	step_y_calc(t_mlx_params *mlx)
{
	float	s_x;
	float	s_y;
	float	x;
	float	y;

	s_x = mlx->pl->x;
	s_y = mlx->pl->y;
	mlx->r->dist_y = 0;
	if (mlx->f->cam_y == 0)
		return ;
	while (1)
	{
		if (mlx->f->cam_y >= 0)
			y = (int)(s_y + 1);
		else if (s_y == mlx->pl->y)
			y = (int)(s_y);
		else
			y = (int)(s_y - 1);
		x = s_x + mlx->f->cam_x * ((y - s_y) / mlx->f->cam_y);
		s_x = x;
		s_y = y;
		if (s_x >= mlx->map->max_x || s_y >= mlx->map->max_y ||
		s_x < 0 || s_y - mlx->r->shift_y < 0 || mlx->map->grid[(int)s_y - mlx->r->shift_y][(int)s_x] == '1')
			break ;
	}
	mlx->r->dist_y = sqrtf(powf(mlx->pl->x - s_x, 2) + powf(mlx->pl->y - s_y, 2));
	if (mlx->r->dist_y < mlx->r->dist_x)
		mlx->r->nwall_x = s_x;
	if (mlx->r->dist_y < mlx->r->dist_x)
		mlx->r->nwall_y = s_y;
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

	// printf("len%f\tdistx%f\tdisty%f\ndx%f\tdy%f\n", len, mlx->r->dist_x, mlx->r->dist_y, dx, dy);
	
	//prints one FoV ray on minimap
	// while (i <= len && x < mlx->map->max_x && y < mlx->map->max_y && mlx->map->grid[(int)y][(int)x] != '1')
	// {
	// 	my_mlx_pixel_put(mlx, x * mlx->map->ratio, y * mlx->map->ratio, rgbtoi(0, 255, 0, 255));
	// 	x = x + (dx / mlx->map->ratio);
	// 	y = y + (dy / mlx->map->ratio);
	// 	i = i + (1 / mlx->map->ratio);
	// }

	// printf("i%i\traylen%f\n", index, sqrtf(exp2f(x - mlx->pl->x) + exp2f(y - mlx->pl->y)));
	// getchar();
	//printf("x%f\ty%f\n", x, y);
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
		put_rov(cos(0.01745*ray), mlx);
		//printf("%f\n", ray);
		ray += nb_ray;
		mlx->r->id++;
	}
	// printf("%i\t%i\t%i\tnbray%f\n", i, mlx->f->fov, mlx->map->res_x, nb_ray);
	mlx->f->cam_x = cam_x;
	mlx->f->cam_y = cam_y;
}
