/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:57:40 by ctaleb            #+#    #+#             */
/*   Updated: 2021/02/01 16:01:39 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_mlx_params	*mlx_data_init(char *path)
{
	t_mlx_params	*mlx;
	t_map			*map_data;
	t_player		*pl_data;

	if (!(map_data = map_open(path)))
		error_handler(0);
	if (!(mlx = malloc(sizeof(t_mlx_params))))
		error_handler(2);
	mlx->map = map_data;
	pl_data = pl_init(map_data);
	mlx->pl = pl_data;
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, mlx->map->size_x,
		mlx->map->size_y, "Cube 3D");
	return (mlx);
}
