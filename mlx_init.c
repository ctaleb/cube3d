/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:57:40 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/10 11:24:35 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_mlx_params	*mlx_data_init(char *path)
{
	t_mlx_params	*mlx;
	t_map			*map_data;
	t_player		*pl_data;
	t_image			*img;

	map_data = map_open(path);
	if (!map_data)
		error_handler(0);
	mlx = malloc(sizeof(t_mlx_params));
	if (!mlx)
		error_handler(2);
	mlx->map = map_data;
	pl_data = pl_init(map_data);
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
