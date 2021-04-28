/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:23:57 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/28 16:31:28 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	bonus_set(t_mlx_params *mlx)
{
	mlx->map->sky_t = NULL;
	mlx->map->door = NULL;
	mlx->map->sp_b_t = NULL;
	mlx->map->hb_t = NULL;
	mlx->map->food_t = NULL;
	mlx->map->trap_t = NULL;
	mlx->map->tp_a_t = NULL;
	mlx->map->tp_b_t = NULL;
	mlx->map->tp_c_t = NULL;
	mlx->map->tp_d_t = NULL;
	mlx->map->key_a = NULL;
	mlx->map->key_b = NULL;
	mlx->map->end_t = NULL;
	mlx->map->go_t = NULL;
	mlx->map->nlvl = NULL;
	mlx->finished = 0;
}

void	map_data_init(t_mlx_params *mlx, char *path)
{
	mlx->d_stage = 0;
	mlx->w_stage = 0;
	mlx->map->grid = NULL;
	mlx->map->dup = NULL;
	mlx->map->res_x = -1;
	mlx->map->res_y = -1;
	mlx->map->flr_c = -1;
	mlx->map->clg_c = -1;
	mlx->map->max_x = 0;
	mlx->map->north = NULL;
	mlx->map->south = NULL;
	mlx->map->east = NULL;
	mlx->map->west = NULL;
	mlx->map->sp_t = NULL;
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
		mlx->map->dup[i] = ft_calloc(mlx->map->max_x + 1, sizeof(char));
		mem_check(mlx->map->dup[i], mlx, 2, mlx->stage);
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

	i = read_cub(mlx);
	validate_mandatory(mlx);
	while (mlx->file[i] != NULL && mlx->file[i][0] == '\0')
		i++;
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
		i++;
	}
	dup_map(mlx->map->grid, mlx->map->dup);
	start_check(mlx->map, mlx);
	if (mlx->map->start_x < 0 || mlx->map->start_y < 0)
		error_handler(27, mlx, 2);
	map_check(mlx->map->start_x, mlx->map->start_y, mlx->map, mlx);
}
