/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:28:38 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/17 12:23:27 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	find_y(t_mlx_params *mlx)
{
	float	temp;

	if (mlx->f->cam_x >= 0)
	{
		mlx->r->n_x = 1;
		mlx->r->s_x = (int)mlx->r->s_x + 1;
	}
	else if (mlx->r->s_x == mlx->pl->x)
	{
		mlx->r->n_x = 0;
		mlx->r->s_x = (int)mlx->r->s_x;
	}
	else
	{
		mlx->r->n_x = -1;
		mlx->r->s_x = (int)mlx->r->s_x - 1;
	}
	mlx->r->s_y = mlx->pl->y + mlx->f->cam_y
		* ((mlx->r->s_x - mlx->pl->x) / mlx->f->cam_x);
	if (mlx->r->n_x == 0)
		mlx->r->n_x -= 1;
	temp = mlx->r->s_y + mlx->f->cam_y * ((mlx->r->n_x) / mlx->f->cam_x);
	mlx->r->n_y = temp - mlx->r->s_y;
}

void	find_x(t_mlx_params *mlx)
{
	float	temp;

	if (mlx->f->cam_y >= 0)
	{
		mlx->r->n_y = 1;
		mlx->r->s_y = (int)mlx->r->s_y + 1;
	}
	else if (mlx->r->s_y == mlx->pl->y)
	{
		mlx->r->n_y = 0;
		mlx->r->s_y = (int)mlx->r->s_y;
	}
	else
	{
		mlx->r->n_y = -1;
		mlx->r->s_y = (int)mlx->r->s_y - 1;
	}
	mlx->r->s_x = mlx->pl->x + mlx->f->cam_x
		* ((mlx->r->s_y - mlx->pl->y) / mlx->f->cam_y);
	if (mlx->r->n_y == 0)
		mlx->r->n_y -= 1;
	temp = mlx->r->s_x + mlx->f->cam_x * ((mlx->r->n_y) / mlx->f->cam_y);
	mlx->r->n_x = temp - mlx->r->s_x;
}