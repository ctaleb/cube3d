/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:23:57 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/24 15:20:00 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
	while (!is_map(mlx->map->file[i]))
		i++;
	j = 0;
	while (mlx->map->file[i] != NULL && is_map(mlx->map->file[i]))
	{
		temp = ft_strlen(mlx->map->file[i++]);
		if (temp > mlx->map->max_x)
			mlx->map->max_x = temp;
		j++;
	}
	mlx->map->max_y = j;
	grid_creator(mlx);
}

void	map_init(t_mlx_params *mlx)
{
	int	i;

	grid_init(mlx);
	i = 0;
	while (mlx->map->file[i])
	{
		analyne(mlx->map, mlx->map->file[i], mlx);
		free(mlx->map->file[i]);
		i++;
	}
	free(mlx->map->file);
	dup_map(mlx->map->grid, mlx->map->dup);
	start_check(mlx->map, mlx);
	map_check(mlx->map->start_x, mlx->map->start_y, mlx->map, mlx);
}
