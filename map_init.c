/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:23:57 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/18 13:50:16 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	bonus_set(t_mlx_params *mlx)
{
	mlx->map->skybox_t = NULL;
	mlx->map->cdoor_t = NULL;
	mlx->map->sec_sp_t = NULL;
	mlx->map->healthbar_t = NULL;
	mlx->map->food_t = NULL;
	mlx->map->trap_t = NULL;
	mlx->map->tp_a_t = NULL;
	mlx->map->tp_b_t = NULL;
	mlx->map->tp_c_t = NULL;
	mlx->map->tp_d_t = NULL;
	mlx->map->key_a_t = NULL;
	mlx->map->key_b_t = NULL;
	mlx->map->ending_t = NULL;
	mlx->map->gameover_t = NULL;
	mlx->map->nextlevel = NULL;
}

void	map_data_init(t_mlx_params *mlx, char *path)
{
	mlx->d_stage = 0;
	mlx->w_stage = 0;
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
	mlx->file = ft_calloc(mlx->map->file_len + 1, sizeof(char *));
	mem_check(mlx->file, mlx, 2, mlx->stage);
	mlx->map->start_x = -1;
	mlx->map->start_y = -1;
	mlx->map->ratio = 0;
	bonus_set(mlx);
}

void	grid_creator(t_mlx_params *mlx)
{
	int	i;

	mlx->map->grid = ft_calloc(mlx->map->max_y + 1, sizeof(char *));
	mem_check(mlx->map->grid, mlx, 2, mlx->stage);
	mlx->map->dup = ft_calloc(mlx->map->max_y + 1, sizeof(char *));
	mem_check(mlx->map->dup, mlx, 2, mlx->stage);
	i = 0;
	while (i < mlx->map->max_y)
	{
		mlx->map->grid[i] = ft_calloc(mlx->map->max_x + 1, sizeof(char));
		mem_check(mlx->map->grid[i], mlx, 2, mlx->stage);
		// matrix_check(mlx->map->grid[i], mlx, i, 0);
		mlx->map->dup[i] = ft_calloc(mlx->map->max_x + 1, sizeof(char));
		mem_check(mlx->map->dup[i], mlx, 2, mlx->stage);
		// matrix_check(mlx->map->dup[i], mlx, i, 1);
		i++;
	}
	mlx->map->ratio = (int)((mlx->map->res_x / mlx->map->res_y
		+ mlx->map->res_x / 10 + mlx->map->res_y / 10)
		/ (mlx->map->max_x / mlx->map->max_y + mlx->map->max_x
		+ mlx->map->max_y));
	if (mlx->map->ratio <= 0)
		mlx->map->ratio = 1;
}

void	grid_init(t_mlx_params *mlx)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (!data_check(mlx->map) && !is_map(mlx->file[i]))
	{
		read_mandatory(i, mlx);
		read_textures(i, mlx);
		read_bonus_sprites(i, mlx);
		read_bonus_textures(i, mlx);
		read_bonus_teleporter(i, mlx);
		read_bonus_info(i, mlx);
//function with other cases?
		// else if (mlx->file[i][0] != '\0')
		// 	error_handler(24, mlx, 4);
		i++;
	}
	while (mlx->file[i] != NULL && mlx->file[i][0] == '\0')
		i++;
	// while (!is_map(mlx->file[i]))
	// 	i++;
	if (mlx->file[i] != NULL && is_map(mlx->file[i]))
		mlx->map->map_id = i;
	else
		error_handler(24, mlx, 4);
	j = 0;
	while (mlx->file[i] != NULL && is_map(mlx->file[i]))
	{
		temp = ft_strlen(mlx->file[i++]);
		if (temp > mlx->map->max_x)
			mlx->map->max_x = temp;
		j++;
	}
	if (mlx->file[i] != NULL && !is_map(mlx->file[i]))
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
	while (mlx->file[i])
	{
		analyne(mlx->map, mlx->file[i]);
		// free(mlx->file[i]);
		i++;
	}
	// free(mlx->file);
	dup_map(mlx->map->grid, mlx->map->dup);
	start_check(mlx->map, mlx);
	map_check(mlx->map->start_x, mlx->map->start_y, mlx->map, mlx);
}
