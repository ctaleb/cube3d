/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:23:57 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/09 15:33:40 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	bonus_set(t_mlx_params *mlx)
{
	mlx->map->skybox_t = NULL;
	mlx->map->sec_sp_t = NULL;
	mlx->map->healthbar_t = NULL;
	mlx->map->food_t = NULL;
	mlx->map->trap_t = NULL;
	mlx->map->tp_a_t = NULL;
	mlx->map->tp_b_t = NULL;
	mlx->map->tp_c_t = NULL;
	mlx->map->tp_d_t = NULL;
	mlx->map->ending_t = NULL;
	mlx->map->gameover_t = NULL;
	mlx->map->nextlevel = NULL;
}

void	map_data_init(t_mlx_params *mlx, char *path)
{
	mlx->map->grid = NULL;
	mlx->map->dup = NULL;
	mlx->map->res_x = -1;
	mlx->map->res_y = -1;
	mlx->map->floor_c = -1;
	mlx->map->ceiling_c = -1;
	mlx->map->max_x = 0;
	mlx->map->north_t = NULL;
	mlx->map->south_t = NULL;
	mlx->map->east_t = NULL;
	mlx->map->west_t = NULL;
	mlx->map->sprite_t = NULL;
	mlx->map->sprite_nb = 0;
	mlx->map->file_len = file_len(path, mlx);
	mlx->map->file = ft_calloc(mlx->map->file_len + 1, sizeof(char *));
	mem_check(mlx->map->file, mlx, 2, 2);
	mlx->map->start_x = -1;
	mlx->map->start_y = -1;
	mlx->map->ratio = 10;
	bonus_set(mlx);
}

void	grid_creator(t_mlx_params *mlx)
{
	int	i;

	mlx->map->grid = ft_calloc(mlx->map->max_y + 1, sizeof(char *));
	mem_check(mlx->map->grid, mlx, 2, 4);
	mlx->map->dup = ft_calloc(mlx->map->max_y + 1, sizeof(char *));
	mem_check(mlx->map->dup, mlx, 2, 5);
	i = 0;
	while (i < mlx->map->max_y)
	{
		mlx->map->grid[i] = ft_calloc(mlx->map->max_x + 1, sizeof(char));
		matrix_check(mlx->map->grid[i], mlx, i, 0);
		mlx->map->dup[i] = ft_calloc(mlx->map->max_x + 1, sizeof(char));
		matrix_check(mlx->map->dup[i], mlx, i, 1);
		i++;
	}
}

void	grid_init(t_mlx_params *mlx)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (!data_check(mlx->map))
	{
		if (mlx->map->file[i][0] == 'R')
			get_resolution(mlx->map, &mlx->map->file[i][1], mlx);
		else if (mlx->map->file[i][0] == 'F' && mlx->map->floor_c < 0)
			mlx->map->floor_c = get_colour(&mlx->map->file[i][1], mlx);
		else if (mlx->map->file[i][0] == 'C' && mlx->map->ceiling_c < 0)
			mlx->map->ceiling_c = get_colour(&mlx->map->file[i][1], mlx);
		else if (mlx->map->file[i][0] == 'S' && mlx->map->file[i][1] != 'O' && !mlx->map->sprite_t)
			mlx->map->sprite_t = get_path(&mlx->map->file[i][1], mlx);
		else if (mlx->map->file[i][0] == 'N' && mlx->map->file[i][1] == 'O' && !mlx->map->north_t)
			mlx->map->north_t = get_path(&mlx->map->file[i][2], mlx);
		else if (mlx->map->file[i][0] == 'S' && mlx->map->file[i][1] == 'O' && !mlx->map->south_t)
			mlx->map->south_t = get_path(&mlx->map->file[i][2], mlx);
		else if (mlx->map->file[i][0] == 'E' && mlx->map->file[i][1] == 'A' && !mlx->map->east_t)
			mlx->map->east_t = get_path(&mlx->map->file[i][2], mlx);
		else if (mlx->map->file[i][0] == 'W' && mlx->map->file[i][1] == 'E' && !mlx->map->west_t)
			mlx->map->west_t = get_path(&mlx->map->file[i][2], mlx);
		else if (mlx->map->file[i][0] == 'B' && mlx->map->file[i][1] == 'X' && !mlx->map->skybox_t)
		{
			mlx->map->skybox_t = get_path(&mlx->map->file[i][2], mlx);
			mlx->defined->skybox = 1;
		}
		else if (mlx->map->file[i][0] == 'H' && mlx->map->file[i][1] == 'B' && !mlx->map->healthbar_t)
		{
			mlx->map->healthbar_t = get_path(&mlx->map->file[i][2], mlx);
			mlx->defined->healthbar = 1;
		}
		else if (mlx->map->file[i][0] == 'O' && mlx->map->file[i][1] == '1' && !mlx->map->food_t)
		{
			mlx->map->food_t = get_path(&mlx->map->file[i][1], mlx);
			// mlx->defined->h_pickup = 1;
		}
		else if (mlx->map->file[i][0] == 'O' && mlx->map->file[i][1] == '2' && !mlx->map->trap_t)
		{
			mlx->map->trap_t = get_path(&mlx->map->file[i][1], mlx);
			// mlx->defined->d_pickup = 1;
		}
		else if (mlx->map->file[i][0] == 'O' && mlx->map->file[i][1] == '3' && !mlx->map->sec_sp_t)
		{
			mlx->map->sec_sp_t = get_path(&mlx->map->file[i][1], mlx);
			// mlx->defined->sec_sp = 1;
		}
		else if (mlx->map->file[i][0] == 'T' && mlx->map->file[i][1] == '1' && !mlx->map->tp_a_t)
		{
			mlx->map->tp_a_t = get_path(&mlx->map->file[i][1], mlx);
			// mlx->defined->teleporter = 1;
		}
		else if (mlx->map->file[i][0] == 'T' && mlx->map->file[i][1] == '2' && !mlx->map->tp_b_t)
			mlx->map->tp_b_t = get_path(&mlx->map->file[i][1], mlx);
		else if (mlx->map->file[i][0] == 'T' && mlx->map->file[i][1] == '3' && !mlx->map->tp_c_t)
			mlx->map->tp_c_t = get_path(&mlx->map->file[i][1], mlx);
		else if (mlx->map->file[i][0] == 'T' && mlx->map->file[i][1] == '4' && !mlx->map->tp_d_t)
			mlx->map->tp_d_t = get_path(&mlx->map->file[i][1], mlx);
		else if (mlx->map->file[i][0] == 'E' && mlx->map->file[i][1] == 'D' && !mlx->map->ending_t)
		{
			mlx->map->ending_t = get_path(&mlx->map->file[i][2], mlx);
			// mlx->defined->ending = 1;
		}
		else if (mlx->map->file[i][0] == 'G' && mlx->map->file[i][1] == 'O' && !mlx->map->gameover_t)
		{
			mlx->map->gameover_t = get_path(&mlx->map->file[i][2], mlx);
			// mlx->defined->gameover = 1;
		}
		else if (mlx->map->file[i][0] == 'N' && mlx->map->file[i][1] == 'L' && !mlx->map->nextlevel)
		{
			mlx->map->nextlevel = get_path(&mlx->map->file[i][2], mlx);
			mlx->defined->nxt_lvl = 1;
		}
		else if (mlx->map->file[i][0] != '\0')
			error_handler(24, mlx, 4);
		i++;
	}
	while (mlx->map->file[i] != NULL && mlx->map->file[i][0] == '\0')
		i++;
	// while (!is_map(mlx->map->file[i]))
	// 	i++;
	if (mlx->map->file[i] != NULL && is_map(mlx->map->file[i]))
		mlx->map->map_id = i;
	else
		error_handler(24, mlx, 4);
	j = 0;
	while (mlx->map->file[i] != NULL && is_map(mlx->map->file[i]))
	{
		temp = ft_strlen(mlx->map->file[i++]);
		if (temp > mlx->map->max_x)
			mlx->map->max_x = temp;
		j++;
	}
	if (mlx->map->file[i] != NULL && !is_map(mlx->map->file[i]))
		error_handler(20, mlx, 4);
	mlx->map->max_y = j;
	grid_creator(mlx);
}

void	map_init(t_mlx_params *mlx)
{
	int	i;

	define_init(mlx);
	grid_init(mlx);
	i = mlx->map->map_id;
	while (mlx->map->file[i])
	{
		analyne(mlx->map, mlx->map->file[i]);
		free(mlx->map->file[i]);
		i++;
	}
	free(mlx->map->file);
	dup_map(mlx->map->grid, mlx->map->dup);
	start_check(mlx->map, mlx);
	map_check(mlx->map->start_x, mlx->map->start_y, mlx->map, mlx);
}
