/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:57:40 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/18 11:58:46 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_mlx_params	*mlx_data_init(char *path)
{
	t_mlx_params	*mlx;
	t_player		*pl_data;
	t_image			*img;

	mlx = malloc(sizeof(t_mlx_params));
	mem_check(mlx, mlx, 2);
	map_open(path, mlx);
	mem_check(mlx->map, mlx, 0);

	pl_data = pl_init(mlx->map);
	mlx->pl = pl_data;
	fov_init(mlx);
	ray_init(mlx);
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, mlx->map->res_x,
			mlx->map->res_y, "Cube 3D");
	img = img_init(mlx);
	mlx->img = img;
	texture_init(mlx);
	sprite_init(mlx);
	input_init(mlx);
	return (mlx);
}
