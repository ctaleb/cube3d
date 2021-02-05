/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:59:41 by ctaleb            #+#    #+#             */
/*   Updated: 2021/02/05 15:49:50 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	tan_x_calc(t_mlx_params *mlx)
{
	float	s_x;
	float	s_y;
	float	x;
	float	y;

	s_x = mlx->pl->x;
	s_y = mlx->pl->y;
	mlx->pl->dist_x = 0;
	while (mlx->map->grid[(int)s_y][(int)s_x] != '1')
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

static void	tan_y_calc(t_mlx_params *mlx)
{
	float	s_x;
	float	s_y;
	float	x;
	float	y;

	s_x = mlx->pl->x;
	s_y = mlx->pl->y;
	mlx->pl->dist_y = 0;
	while (mlx->map->grid[(int)s_y][(int)s_x] != '1')
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

void	dist_calc(t_mlx_params *mlx)
{
	tan_x_calc(mlx);
	tan_y_calc(mlx);
}

int		wall_check(float x, float y, t_mlx_params *mlx)
{
	if (mlx->pl->cam_x >= 0 && mlx->pl->cam_y <= 0)
	{
		if (x > mlx->pl->nwall_x && y < mlx->pl->nwall_y + 1.1)
			return (0);
	}
	else if (mlx->pl->cam_x >= 0 && mlx->pl->cam_y >= 0)
	{
		if (x > mlx->pl->nwall_x && y > mlx->pl->nwall_y)
			return (0);
	}
	else if (mlx->pl->cam_x <= 0 && mlx->pl->cam_y >= 0)
	{
		if (x < mlx->pl->nwall_x + 1.1 && y > mlx->pl->nwall_y)
			return (0);
	}
	else if (mlx->pl->cam_x <= 0 && mlx->pl->cam_y <= 0)
	{
		if (x < mlx->pl->nwall_x + 1.1 && y < mlx->pl->nwall_y)
			return (0);
	}
	return (1);
}