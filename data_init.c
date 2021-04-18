/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:56:06 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/18 13:33:55 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ray_init(t_mlx_params *mlx)
{
	mlx->r = malloc(sizeof(t_ray));
	mem_check(mlx->r, mlx, 2, mlx->stage);
	mlx->r->id = 0;
	mlx->r->pos = 0;
	mlx->r->nwall_x = 0;
	mlx->r->nwall_y = 0;
	mlx->r->nt_x = 1;
	mlx->r->nt_y = 1;
	mlx->r->nt = 1;
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
	mem_check(mlx->f, mlx, 2, mlx->stage);
	mlx->f->fov = 30;
	mlx->f->multi = 1 + mlx->map->res_x / 700;
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
	mem_check(mlx->f->dist, mlx, 2, mlx->stage);
	mlx->f->shade = malloc(sizeof(float) * ((int)(mlx->map->res_y * 1.3)));
	mem_check(mlx->f->shade, mlx, 2, mlx->stage);
	shader(mlx);
	rotate_pl(123, mlx, 0.05);
	rotate_pl(124, mlx, 0.05);
}

void	pl_init(t_mlx_params *mlx)
{
	mlx->pl = malloc(sizeof(t_player));
	mem_check(mlx->pl, mlx, 2, mlx->stage);
	mlx->pl->x = mlx->map->start_x + 0.5;
	mlx->pl->y = mlx->map->start_y + 0.5;
	mlx->pl->f_x = 0;
	mlx->pl->f_y = 0;
	mlx->pl->health = 100;
	mlx->pl->colour = rgbtoi(0, 255, 0, 0);
}

void	define_init(t_mlx_params *mlx)
{
	mlx->defined = malloc(sizeof(t_defined));
	mem_check(mlx->defined, mlx, 2, mlx->stage);
	mlx->d_stage = mlx->stage;
	mlx->defined->nxt_lvl = 0;
	mlx->defined->skybox = 0;
	mlx->defined->cdoor = 0;
	mlx->defined->healthbar = 0;
	mlx->defined->h_pickup = 0;
	mlx->defined->d_pickup = 0;
	mlx->defined->sec_sp = 0;
	mlx->defined->tp_a = 0;
	mlx->defined->tp_b = 0;
	mlx->defined->tp_c = 0;
	mlx->defined->tp_d = 0;
	mlx->defined->key_a = 0;
	mlx->defined->key_b = 0;
	mlx->defined->ending = 0;
	mlx->defined->gameover = 0;
	mlx->defined->sprite = 0;
	mlx->defined->north = 0;
	mlx->defined->south = 0;
	mlx->defined->east = 0;
	mlx->defined->west = 0;
}
