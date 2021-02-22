/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:59:41 by ctaleb            #+#    #+#             */
/*   Updated: 2021/02/22 12:23:33 by ctaleb           ###   ########lyon.fr   */
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
		//printf("%f\t%f\t%f\t%f\t%c\n", s_x, s_y, x, y, mlx->map->grid[(int)s_y][(int)s_x]);
		mlx->pl->dist_x += sqrtf(powf(s_x - x, 2) + powf(s_y - y, 2));
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
		//printf("%f\t%f\t%f\t%f\n", s_x, s_y, x, y);
		mlx->pl->dist_y += sqrtf(powf(s_y - y, 2) + powf(s_x - x, 2));
		s_x = x;
		s_y = y;
	}
	if (mlx->pl->dist_y < mlx->pl->dist_x)
		mlx->pl->nwall_x = s_x;
	if (mlx->pl->dist_y < mlx->pl->dist_x)
		mlx->pl->nwall_y = s_y;
}

void	inverse_cam(char dir, t_mlx_params *mlx)
{
	if (dir == 'B')
	{
		mlx->pl->cam_x *= -1;
		mlx->pl->cam_y *= -1;
	}
}

void	dist_calc(char dir, t_mlx_params *mlx)
{
	inverse_cam(dir, mlx);
	tan_x_calc(mlx);
	tan_y_calc(mlx);
	inverse_cam(dir, mlx);
}

int		wall_check(float x, float y, t_mlx_params *mlx)
{
	int c_x;
	int c_y;

	c_x = (int)x;
	c_y = (int)y;
	if ((mlx->pl->cam_x >= 0 && mlx->pl->cam_y <= 0)
	&& ((x >= mlx->pl->nwall_x && y <= mlx->pl->nwall_y)
	|| (mlx->map->grid[c_y][c_x] == '1')))
		return (0);
	else if ((mlx->pl->cam_x >= 0 && mlx->pl->cam_y >= 0)
	&& ((x >= mlx->pl->nwall_x && y >= mlx->pl->nwall_y)
	|| (mlx->map->grid[c_y][c_x] == '1')))
		return (0);
	else if ((mlx->pl->cam_x <= 0 && mlx->pl->cam_y >= 0)
	&& ((x <= mlx->pl->nwall_x && y >= mlx->pl->nwall_y)
	|| (mlx->map->grid[c_y][c_x] == '1')))
		return (0);
	else if ((mlx->pl->cam_x <= 0 && mlx->pl->cam_y <= 0)
	&& ((x <= mlx->pl->nwall_x && y <= mlx->pl->nwall_y)
	|| (mlx->map->grid[c_y][c_x] == '1')))
		return (0);
	return (1);
}
