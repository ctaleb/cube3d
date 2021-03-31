/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:56:06 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/31 11:20:56 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ray_init(t_mlx_params *mlx)
{
	mlx->r = malloc(sizeof(t_ray));
	mem_check(mlx->r, mlx, 2, 11);
	mlx->r->id = 0;
	mlx->r->pos = 0;
	mlx->r->nwall_x = 0;
	mlx->r->nwall_y = 0;
	mlx->r->dist_x = 0;
	mlx->r->dist_y = 0;
	mlx->r->shift_x = 0;
	mlx->r->shift_y = 0;
	mlx->r->s_x = 0;
	mlx->r->s_y = 0;
	mlx->r->n_x = 0;
	mlx->r->n_y = 0;
	mlx->r->side = 0;
	mlx->r->u_wall = 0;
	mlx->r->l_wall = 0;
}

void	fov_init(t_mlx_params *mlx)
{
	mlx->f = malloc(sizeof(t_fov));
	mem_check(mlx->f, mlx, 2, 8);
	mlx->f->fov = 30;
	mlx->f->cam_x = 0;
	mlx->f->cam_y = 0;
	if (mlx->map->grid[mlx->map->start_y][mlx->map->start_x] == 'N')
		mlx->f->cam_y = -2;
	else if (mlx->map->grid[mlx->map->start_y][mlx->map->start_x] == 'S')
		mlx->f->cam_y = 2;
	else if (mlx->map->grid[mlx->map->start_y][mlx->map->start_x] == 'E')
		mlx->f->cam_x = 2;
	else if (mlx->map->grid[mlx->map->start_y][mlx->map->start_x] == 'W')
		mlx->f->cam_x = -2;
	mlx->f->dist = malloc(sizeof(float) * mlx->map->res_x);
	mem_check(mlx->f->dist, mlx, 2, 9);
	mlx->f->shade = malloc(sizeof(float) * mlx->map->res_y);
	mem_check(mlx->f->shade, mlx, 2, 10);
	shader(mlx);
	rotate_pl(123, mlx, 0.05);
	rotate_pl(124, mlx, 0.05);
}

void	pl_init(t_mlx_params *mlx)
{
	mlx->pl = malloc(sizeof(t_player));
	mem_check(mlx->pl, mlx, 2, 7);
	mlx->pl->x = mlx->map->start_x + 0.5;
	mlx->pl->y = mlx->map->start_y + 0.5;
	mlx->pl->f_x = 0;
	mlx->pl->f_y = 0;
	mlx->pl->colour = rgbtoi(0, 255, 0, 0);
}
