/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_gen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 11:38:27 by ctaleb            #+#    #+#             */
/*   Updated: 2021/02/25 12:40:36 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_image	*img_init(t_mlx_params *mlx)
{
	t_image		*image;

	image = malloc(sizeof(t_image));
	if (!image)
		error_handler(2);
	image->ptr = mlx_new_image(mlx->ptr, mlx->map->res_x, mlx->map->res_y);
	image->addr = mlx_get_data_addr(image->ptr, &image->bpp, &image->len, &image->endian);
	return (image);
}

void	my_mlx_pixel_put(t_mlx_params *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->img->addr + (y * mlx->img->len + x * (mlx->img->bpp / 8));
	*(unsigned int *)dst = color;
}

// static void print_txt(t_mlx_params *mlx)
// {
// 	int x;
// 	int y;

// 	y = 0;
// 	while (y < mlx->n_txt->height)
// 	{
// 		x = 0;
// 		while (x < mlx->n_txt->width)
// 		{
// 			my_mlx_pixel_put(mlx, x, y, mlx->n_txt->addr[y * mlx->n_txt->width + x]);
// 			x++;
// 		}
// 		y++;
// 	}
// }

int	frame_gen(t_mlx_params *mlx)
{
	//mlx_clear_window(mlx->ptr, mlx->win);
	put_fov(mlx);
	print_minimap(mlx);
	put_camera(mlx);
	put_player(mlx);
	//ray_cannon(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img->ptr, 0, 0);
	return (0);
}