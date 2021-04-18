/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 13:59:18 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/18 12:59:04 by ctaleb           ###   ########lyon.fr   */
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
		mlx->map->food_t = get_path(&mlx->file[i][2], mlx->map->food_t, mlx);
		mlx->defined->h_pickup = 1;
	}
	else if (mlx->file[i][0] == 'O' && mlx->file[i][1] == '2')
	{
		mlx->map->trap_t = get_path(&mlx->file[i][2], mlx->map->trap_t, mlx);
		mlx->defined->d_pickup = 1;
	}
	else if (mlx->file[i][0] == 'O' && mlx->file[i][1] == '3')
	{
		mlx->map->sec_sp_t = get_path(&mlx->file[i][2], mlx->map->sec_sp_t, mlx);
		mlx->defined->sec_sp = 1;
	}
}

void	read_bonus_textures(int i, t_mlx_params *mlx)
{
	if (mlx->file[i][0] == 'B' && mlx->file[i][1] == 'X')
	{
		mlx->map->skybox_t = get_path(&mlx->file[i][2], mlx->map->skybox_t, mlx);
		mlx->defined->skybox = 1;
	}
	else if (mlx->file[i][0] == 'H' && mlx->file[i][1] == 'B')
	{
		mlx->map->healthbar_t = get_path(&mlx->file[i][2], mlx->map->healthbar_t, mlx);
		mlx->defined->healthbar = 1;
	}
	else if (mlx->file[i][0] == 'G' && mlx->file[i][1] == 'O')
	{
		mlx->map->gameover_t = get_path(&mlx->file[i][2], mlx->map->gameover_t, mlx);
		// mlx->defined->gameover = 1;
	}
	else if (mlx->file[i][0] == 'E' && mlx->file[i][1] == 'D')
	{
		mlx->map->ending_t = get_path(&mlx->file[i][2], mlx->map->ending_t, mlx);
		// mlx->defined->ending = 1;
	}
}

void	read_bonus_teleporter(int i, t_mlx_params *mlx)
{
	if (mlx->file[i][0] == 'T' && mlx->file[i][1] == '1')
	{
		mlx->map->tp_a_t = get_path(&mlx->file[i][2], mlx->map->tp_a_t, mlx);
		mlx->defined->tp_a = 1;
	}
	else if (mlx->file[i][0] == 'T' && mlx->file[i][1] == '2')
	{
		mlx->map->tp_b_t = get_path(&mlx->file[i][2], mlx->map->tp_b_t, mlx);
		mlx->defined->tp_b = 1;
	}
	else if (mlx->file[i][0] == 'T' && mlx->file[i][1] == '3')
	{
		mlx->map->tp_c_t = get_path(&mlx->file[i][2], mlx->map->tp_c_t, mlx);
		mlx->defined->tp_c = 1;
	}
	else if (mlx->file[i][0] == 'T' && mlx->file[i][1] == '4')
	{
		mlx->map->tp_d_t = get_path(&mlx->file[i][2], mlx->map->tp_d_t, mlx);
		mlx->defined->tp_d = 1;
	}
}

void	read_bonus_info(int i, t_mlx_params *mlx)
{
	if (mlx->file[i][0] == 'N' && mlx->file[i][1] == 'L')
	{
		mlx->map->nextlevel = get_path(&mlx->file[i][2], mlx->map->nextlevel, mlx);
		mlx->defined->nxt_lvl = 1;
	}
	else if (mlx->file[i][0] == 'D' && mlx->file[i][1] == 'C')
	{
		mlx->map->cdoor_t = get_path(&mlx->file[i][2], mlx->map->cdoor_t, mlx);
		mlx->defined->cdoor = 1;
	}
	else if (mlx->file[i][0] == 'K' && mlx->file[i][1] == '1')
	{
		mlx->map->key_a_t = get_path(&mlx->file[i][2], mlx->map->key_a_t, mlx);
		mlx->defined->key_a = 1;
	}
	else if (mlx->file[i][0] == 'K' && mlx->file[i][1] == '2')
	{
		mlx->map->key_b_t = get_path(&mlx->file[i][2], mlx->map->key_b_t, mlx);
		mlx->defined->key_b = 1;
	}
}
