/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:57:40 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/24 13:16:32 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_mlx_params	*mlx_data_init(char *path)
{
	t_mlx_params	*mlx;

	mlx = malloc(sizeof(t_mlx_params));
	mem_check(mlx, mlx, 2, 0);
	map_open(path, mlx);
	pl_init(mlx);
	fov_init(mlx);
	ray_init(mlx);
	mlx->ptr = mlx_init();
	mem_check(mlx->ptr, mlx, 2, 11);
	mlx->win = mlx_new_window(mlx->ptr, mlx->map->res_x,
			mlx->map->res_y, "Cube 3D");
	mem_check(mlx->win, mlx, 2, 12);
	img_init(mlx);
	texture_init(mlx);
	sprite_init(mlx);
	input_init(mlx);
	return (mlx);
}
