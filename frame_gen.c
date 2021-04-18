/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_gen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 11:38:27 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/18 15:40:03 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	img_init(t_mlx_params *mlx)
{
	mlx->w_stage = mlx->stage;
	mlx->img = malloc(sizeof(t_image));
	mem_check(mlx->img, mlx, 2, mlx->stage);
	mlx->img->ptr = mlx_new_image(mlx->ptr,
			mlx->map->res_x, mlx->map->res_y);
	mem_check(mlx->img, mlx, 2, -1);
	mlx->img->addr = mlx_get_data_addr(mlx->img->ptr,
			&mlx->img->bpp, &mlx->img->len, &mlx->img->endian);
}

void	my_mlx_pixel_put(t_mlx_params *mlx, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < mlx->map->res_x && y < mlx->map->res_y)
	{
		dst = mlx->img->addr + (y * mlx->img->len + x
				* (mlx->img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	my_mlx_multi_put(t_mlx_params *mlx, int x, int y, int color)
{
	int	i;

	i = 0;
	while (i < mlx->f->multi)
	{
		my_mlx_pixel_put(mlx, x, y, color);
		x++;
		i++;
	}
}

static void	framer(t_mlx_params *mlx)
{
	sprite_reset(mlx);
	movement(mlx);
	put_sky(mlx);
	action(mlx);
	put_fov(mlx);
	sprite_check(mlx);
	if (mlx->map->max_y <= mlx->map->res_y / 2
		|| mlx->map->max_x <= mlx->map->res_x / 2)
	{
		print_minimap(mlx);
		put_camera(mlx);
		put_player(mlx);
	}
	put_healthbar(mlx);
}

int	frame_gen(t_mlx_params *mlx)
{
	if (!mlx->finished && mlx->pl->health > 0)
		framer(mlx);
	else if (mlx->finished)
		put_ending(mlx);
	else if (mlx->gameover)
		put_gameover(mlx);
	if (mlx->save)
	{
		create_bitmap(mlx);
		free_all(mlx, 31);
		exit (0);
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img->ptr, 0, 0);
	return (0);
}
