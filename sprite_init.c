/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:20:18 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/24 13:40:07 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	sprite_creator(int count, int x, int y, t_mlx_params *mlx)
{
	mlx->sp[count] = malloc(sizeof(t_sprites));
	sp_check(mlx->sp[count], mlx, count);
	mlx->sp[count]->id = count;
	mlx->sp[count]->type = 0;
	mlx->sp[count]->active = 1;
	mlx->sp[count]->visible = 0;
	mlx->sp[count]->x = x + 0.5;
	mlx->sp[count]->y = y + 0.5;
	mlx->sp[count]->dist = sqrtf(powf(mlx->sp[count]->x - mlx->pl->x, 2)
			+ powf(mlx->sp[count]->y - mlx->pl->y, 2));
}

void	sprite_finder(t_mlx_params *mlx)
{
	int			count;
	int			i;
	int			j;

	count = 0;
	i = 0;
	while (mlx->map->grid[i])
	{
		j = 0;
		while (mlx->map->grid[i][j])
		{
			if (mlx->map->grid[i][j] == '2')
			{
				sprite_creator(count, j, i, mlx);
				count++;
			}
			j++;
		}
		i++;
	}
}

// void	sprite_texture_init(t_mlx_params *mlx)
// {

// }

void	sprite_init(t_mlx_params *mlx)
{
	mlx->sp = malloc(sizeof(t_sprites *) * mlx->map->sprite_nb);
	mem_check(mlx->sp, mlx, 2, 23);
	sprite_finder(mlx);
	mlx->sp_txt = malloc(sizeof(t_texture));
	mem_check(mlx->sp_txt, mlx, 2, 25);
	mlx->sp_txt->ptr = mlx_xpm_file_to_image(mlx->ptr, mlx->map->sprite_t,
			&mlx->sp_txt->width, &mlx->sp_txt->height);
	mlx->sp_txt->addr = (int *)mlx_get_data_addr(mlx->sp_txt->ptr,
			&mlx->sp_txt->bpp, &mlx->sp_txt->len, &mlx->sp_txt->endian);
	mem_check(mlx->sp_txt->ptr, mlx, 13, 26);
}
