/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:56:06 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/16 12:52:24 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void		ray_init(t_mlx_params *mlx)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		error_handler(2);
	ray->id = 0;
	ray->pos = 0;
	ray->nwall_x = 0;
	ray->nwall_y = 0;
	ray->dist_x = 0;
	ray->dist_y = 0;
	ray->shift_x = 0;
	ray->shift_y = 0;
	ray->s_x = 0;
	ray->s_y = 0;
	ray->n_x = 0;
	ray->n_y = 0;
	ray->side = 0;
	ray->u_wall = 0;
	ray->l_wall = 0;
	mlx->r = ray;
}

void		fov_init(t_mlx_params *mlx)
{
	t_fov	*fov;

	fov = malloc(sizeof(t_fov));
	if (!fov)
		error_handler(2);
	fov->fov = 30;
	fov->cam_x = 0;
	fov->cam_y = 0;
	if (mlx->map->grid[mlx->map->start_y][mlx->map->start_x] == 'N')
		fov->cam_y = -2;
	else if (mlx->map->grid[mlx->map->start_y][mlx->map->start_x] == 'S')
		fov->cam_y = 2;
	else if (mlx->map->grid[mlx->map->start_y][mlx->map->start_x] == 'E')
		fov->cam_x = 2;
	else if (mlx->map->grid[mlx->map->start_y][mlx->map->start_x] == 'W')
		fov->cam_x = -2;
	fov->dist = malloc(sizeof(float) * mlx->map->res_x);
	if (!fov->dist)
		error_handler(2);
	mlx->f = fov;
	rotate_pl(123, mlx, 0.05);
	rotate_pl(124, mlx, 0.05);
}

t_player	*pl_init(t_map *map_data)
{
	t_player	*pl_data;

	pl_data = malloc(sizeof(t_player));
	if (!pl_data)
		error_handler(2);
	pl_data->x = map_data->start_x + 0.5;
	pl_data->y = map_data->start_y + 0.5;
	pl_data->f_x = 0;
	pl_data->f_y = 0;
	pl_data->colour = rgbtoi(0, 255, 0, 0);
	return (pl_data);
}
