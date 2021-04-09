/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:59:41 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/09 13:02:04 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	cmp_dist(float s_x, float s_y, t_mlx_params *mlx)
{
	if (mlx->r->dist_y < mlx->r->dist_x)
	{
		mlx->r->nwall_x = s_x;
		mlx->r->nwall_y = s_y;
	}
}

static void	dist_x_calc(t_mlx_params *mlx)
{
	float	s_x;
	float	s_y;
	float	x;
	float	y;

	s_x = mlx->pl->x;
	s_y = mlx->pl->y;
	mlx->r->dist_x = 0;
	while (s_x < mlx->map->max_x && s_y < mlx->map->max_y
		&& s_x >= 0 && s_y >= 0 && mlx->map->grid[(int)s_y][(int)s_x] != '1')
	{
		if (mlx->f->cam_x >= 0)
			x = (int)(s_x + 1);
		else if (s_x == mlx->pl->x)
			x = (int)(s_x);
		else
			x = (int)(s_x - 1);
		y = s_y + mlx->f->cam_y * ((x - s_x) / mlx->f->cam_x);
		mlx->r->dist_x += sqrtf(powf(s_x - x, 2) + powf(s_y - y, 2));
		s_x = x;
		s_y = y;
	}
	mlx->r->nwall_x = s_x;
	mlx->r->nwall_y = s_y;
}

static void	dist_y_calc(t_mlx_params *mlx)
{
	float	s_x;
	float	s_y;
	float	x;
	float	y;

	s_x = mlx->pl->x;
	s_y = mlx->pl->y;
	mlx->r->dist_y = 0;
	while (s_x < mlx->map->max_x && s_y < mlx->map->max_y
		&& s_x >= 0 && s_y >= 0 && mlx->map->grid[(int)s_y][(int)s_x] != '1')
	{
		if (mlx->f->cam_y >= 0)
			y = (int)(s_y + 1);
		else if (s_y == mlx->pl->y)
			y = (int)(s_y);
		else
			y = (int)(s_y - 1);
		x = s_x + mlx->f->cam_x * ((y - s_y) / mlx->f->cam_y);
		mlx->r->dist_y += sqrtf(powf(s_y - y, 2) + powf(s_x - x, 2));
		s_x = x;
		s_y = y;
	}
	cmp_dist(s_x, s_y, mlx);
}

void	wall_dist_calc(char dir, t_mlx_params *mlx)
{
	inverse_cam(dir, mlx);
	dist_x_calc(mlx);
	dist_y_calc(mlx);
	inverse_cam(dir, mlx);
}

int	wall_check(float x, float y, t_mlx_params *mlx)
{
	if (mlx->map->grid[(int)y][(int)x] == '1'
		|| mlx->map->grid[(int)y][(int)x] == '2'
		|| mlx->map->grid[(int)y][(int)x] == '4')
		return (0);
	else if (mlx->map->grid[(int)y][(int)x] == '5')
		if (mlx->pl->health > 80)
			mlx->pl->health = 100;
		else
			mlx->pl->health += 20;
	else if (mlx->map->grid[(int)y][(int)x] == '6')
	{
		if (mlx->pl->health < 80)
			mlx->pl->health = 0;
		else
			mlx->pl->health -= 20;
	}
	return (1);
}
