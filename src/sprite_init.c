/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:20:18 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/21 13:19:25 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	sprite_creator(int count, int x, int y, t_mlx_params *mlx)
{
	mlx->sp[count] = malloc(sizeof(t_sprites));
	mem_check(mlx->sp[count], mlx, 2, mlx->stage);
	mlx->sp[count]->id = count;
	if (mlx->map->grid[y][x] == 'K')
		mlx->sp[count]->type = 10;
	else
		mlx->sp[count]->type = (int)mlx->map->grid[y][x] - 48;
	mlx->sp[count]->state = 0;
	mlx->sp[count]->active = 1;
	mlx->sp[count]->visible = 0;
	mlx->sp[count]->x = x + 0.5;
	mlx->sp[count]->y = y + 0.5;
	mlx->sp[count]->door_x = 0;
	mlx->sp[count]->door_y = 0;
	if (mlx->sp[count]->type == 10)
		link_door(mlx, count, x, y);
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
			if (mlx->map->grid[i][j] == '2'
				|| mlx->map->grid[i][j] == '4'
				|| mlx->map->grid[i][j] == '5'
				|| mlx->map->grid[i][j] == '6'
				|| mlx->map->grid[i][j] == '9'
				|| mlx->map->grid[i][j] == 'K')
			{
				sprite_creator(count, j, i, mlx);
				count++;
			}
			j++;
		}
		i++;
	}
}

t_texture	*texturer(t_mlx_params *mlx, char *path, int *check)
{
	t_texture	*texture;

	texture = malloc(sizeof(t_texture));
	mem_check(texture, mlx, 2, mlx->stage);
	texture->ptr = mlx_xpm_file_to_image(mlx->ptr, path,
			&texture->width, &texture->height);
	mem_check(texture->ptr, mlx, 13, -1);
	*check += 1;
	texture->addr = (int *)mlx_get_data_addr(texture->ptr,
			&texture->bpp, &texture->len, &texture->endian);
	return (texture);
}

void	bonus_sprites(t_mlx_params *mlx)
{
	if (mlx->def->h_pickup)
		mlx->h_pickup = texturer(mlx, mlx->map->food_t, &mlx->def->h_pickup);
	if (mlx->def->d_pickup)
		mlx->d_pickup = texturer(mlx, mlx->map->trap_t, &mlx->def->d_pickup);
	if (mlx->def->sec_sp)
		mlx->sec_sp = texturer(mlx, mlx->map->sp_b_t, &mlx->def->sec_sp);
	if (mlx->def->tp_a)
		mlx->tp_a = texturer(mlx, mlx->map->tp_a_t, &mlx->def->tp_a);
	if (mlx->def->tp_b)
		mlx->tp_b = texturer(mlx, mlx->map->tp_b_t, &mlx->def->tp_b);
	if (mlx->def->tp_c)
		mlx->tp_c = texturer(mlx, mlx->map->tp_c_t, &mlx->def->tp_c);
	if (mlx->def->tp_d)
		mlx->tp_d = texturer(mlx, mlx->map->tp_d_t, &mlx->def->tp_d);
	if (mlx->def->key_a)
		mlx->key_a = texturer(mlx, mlx->map->key_a, &mlx->def->key_a);
	if (mlx->def->key_b)
		mlx->key_b = texturer(mlx, mlx->map->key_b, &mlx->def->key_b);
}

void	sprite_init(t_mlx_params *mlx)
{
	mlx->sp = malloc(sizeof(t_sprites *) * mlx->map->sprite_nb);
	mem_check(mlx->sp, mlx, 2, mlx->stage);
	sprite_finder(mlx);
	mlx->sp_txt = malloc(sizeof(t_texture));
	mem_check(mlx->sp_txt, mlx, 2, -1);
	mlx->sp_txt->ptr = mlx_xpm_file_to_image(mlx->ptr, mlx->map->sp_t,
			&mlx->sp_txt->width, &mlx->sp_txt->height);
	mem_check(mlx->sp_txt->ptr, mlx, 13, -1);
	mlx->def->sprite += 1;
	mlx->sp_txt->addr = (int *)mlx_get_data_addr(mlx->sp_txt->ptr,
			&mlx->sp_txt->bpp, &mlx->sp_txt->len, &mlx->sp_txt->endian);
	bonus_sprites(mlx);
}
