/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 13:59:18 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/24 17:30:10 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	read_mandatory(int i, t_mlx_params *mlx)
{
	if (mlx->file[i][0] == 'R')
		get_resolution(mlx->map, &mlx->file[i][1], mlx);
	else if (mlx->file[i][0] == 'F' && mlx->map->floor_c < 0)
		mlx->map->floor_c = get_colour(&mlx->file[i][1], mlx);
	else if (mlx->file[i][0] == 'C' && mlx->map->ceiling_c < 0)
		mlx->map->ceiling_c = get_colour(&mlx->file[i][1], mlx);
}

void	read_bonus_sprites(int i, t_mlx_params *mlx)
{
	if (mlx->file[i][0] == 'O' && mlx->file[i][1] == '1')
	{
		mlx->map->food_t = get_path(&mlx->file[i][2], mlx->map->food_t, mlx, 1);
		mlx->def->h_pickup = 1;
	}
	else if (mlx->file[i][0] == 'O' && mlx->file[i][1] == '2')
	{
		mlx->map->trap_t = get_path(&mlx->file[i][2], mlx->map->trap_t, mlx, 1);
		mlx->def->d_pickup = 1;
	}
	else if (mlx->file[i][0] == 'O' && mlx->file[i][1] == '3')
	{
		mlx->map->sp_b_t = get_path(&mlx->file[i][2], mlx->map->sp_b_t, mlx, 1);
		mlx->def->sec_sp = 1;
	}
}

void	read_bonus_textures(int i, t_mlx_params *mlx)
{
	if (mlx->file[i][0] == 'B' && mlx->file[i][1] == 'X')
	{
		mlx->map->sky_t = get_path(&mlx->file[i][2], mlx->map->sky_t, mlx, 1);
		mlx->def->skybox = 1;
	}
	else if (mlx->file[i][0] == 'H' && mlx->file[i][1] == 'B')
	{
		mlx->map->hb_t = get_path(&mlx->file[i][2], mlx->map->hb_t, mlx, 1);
		mlx->def->hb = 1;
	}
	else if (mlx->file[i][0] == 'G' && mlx->file[i][1] == 'O')
	{
		mlx->map->go_t = get_path(&mlx->file[i][2], mlx->map->go_t, mlx, 1);
		mlx->def->go = 1;
	}
	else if (mlx->file[i][0] == 'E' && mlx->file[i][1] == 'D')
	{
		mlx->map->end_t = get_path(&mlx->file[i][2], mlx->map->end_t, mlx, 1);
		mlx->def->ending = 1;
	}
}

void	read_bonus_teleporter(int i, t_mlx_params *mlx)
{
	if (mlx->file[i][0] == 'T' && mlx->file[i][1] == '1')
	{
		mlx->map->tp_a_t = get_path(&mlx->file[i][2], mlx->map->tp_a_t, mlx, 1);
		mlx->def->tp_a = 1;
	}
	else if (mlx->file[i][0] == 'T' && mlx->file[i][1] == '2')
	{
		mlx->map->tp_b_t = get_path(&mlx->file[i][2], mlx->map->tp_b_t, mlx, 1);
		mlx->def->tp_b = 1;
	}
	else if (mlx->file[i][0] == 'T' && mlx->file[i][1] == '3')
	{
		mlx->map->tp_c_t = get_path(&mlx->file[i][2], mlx->map->tp_c_t, mlx, 1);
		mlx->def->tp_c = 1;
	}
	else if (mlx->file[i][0] == 'T' && mlx->file[i][1] == '4')
	{
		mlx->map->tp_d_t = get_path(&mlx->file[i][2], mlx->map->tp_d_t, mlx, 1);
		mlx->def->tp_d = 1;
	}
}

void	read_bonus_info(int i, t_mlx_params *mlx)
{
	if (mlx->file[i][0] == 'N' && mlx->file[i][1] == 'L')
	{
		mlx->map->nlvl = get_path(&mlx->file[i][2], mlx->map->nlvl, mlx, 0);
		mlx->def->nxt_lvl = 1;
	}
	else if (mlx->file[i][0] == 'D' && mlx->file[i][1] == 'C')
	{
		mlx->map->door = get_path(&mlx->file[i][2], mlx->map->door, mlx, 1);
		mlx->def->door = 1;
	}
	else if (mlx->file[i][0] == 'K' && mlx->file[i][1] == '1')
	{
		mlx->map->key_a = get_path(&mlx->file[i][2], mlx->map->key_a, mlx, 1);
		mlx->def->key_a = 1;
	}
	else if (mlx->file[i][0] == 'K' && mlx->file[i][1] == '2')
	{
		mlx->map->key_b = get_path(&mlx->file[i][2], mlx->map->key_b, mlx, 1);
		mlx->def->key_b = 1;
	}
}
