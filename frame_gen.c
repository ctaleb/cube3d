/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_gen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 11:38:27 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/24 12:38:15 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	img_init(t_mlx_params *mlx)
{
	mlx->img = malloc(sizeof(t_image));
	mem_check(mlx->img, mlx, 2, 13);
	mlx->img->ptr = mlx_new_image(mlx->ptr,
			mlx->map->res_x, mlx->map->res_y);
	mem_check(mlx->img, mlx, 2, 14);
	mlx->img->addr = mlx_get_data_addr(mlx->img->ptr,
			&mlx->img->bpp, &mlx->img->len, &mlx->img->endian);
}

void	my_mlx_pixel_put(t_mlx_params *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->img->addr + (y * mlx->img->len + x
			* (mlx->img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	frame_gen(t_mlx_params *mlx)
{
	sprite_reset(mlx);
	movement(mlx);
	put_fov(mlx);
	sprite_check(mlx);
	print_minimap(mlx);
	put_camera(mlx);
	put_player(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img->ptr, 0, 0);
	return (0);
}
