/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:23:57 by ctaleb            #+#    #+#             */
/*   Updated: 2021/01/25 16:20:18 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	map_data_init(t_map *map_data, char *path)
{
	map_data->grid = NULL;
	map_data->dup = NULL;
	map_data->size_x = -1;
	map_data->size_y = -1;
	map_data->floor_c = -1;
	map_data->ceiling_c = -1;
	map_data->max_x = 0;
	map_data->north_t = NULL;
	map_data->south_t = NULL;
	map_data->east_t = NULL;
	map_data->west_t = NULL;
	map_data->sprite_t = NULL;
	map_data->file = ft_calloc(file_len(path) + 1, sizeof(char *));
	map_data->start_x = -1;
	map_data->start_y = -1;
}

void	grid_init(t_map *map_data)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (!is_map(map_data->file[i]))
		i++;
	j = 0;
	while (map_data->file[i] != NULL && is_map(map_data->file[i]))
	{
		temp = ft_strlen(map_data->file[i++]);
		if (temp > map_data->max_x)
			map_data->max_x = temp;
		j++;
	}
	map_data->max_y = j;
	map_data->grid = ft_calloc(map_data->max_y + 1, sizeof(char *));
	map_data->dup = ft_calloc(map_data->max_y + 1, sizeof(char *));
	i = 0;
	while (i < j)
	{
		map_data->grid[i] = ft_calloc(map_data->max_x + 1, sizeof(char));
		map_data->dup[i] = ft_calloc(map_data->max_x + 1, sizeof(char));
		i++;
	}
}

void	map_init(t_map *map_data)
{
	int	i;

	grid_init(map_data);
	i = 0;
	while (map_data->file[i])
	{
		analyne(map_data, map_data->file[i]);
		free(map_data->file[i]);
		i++;
	}
	free(map_data->file);
	dup_map(map_data->grid, map_data->dup);
	start_check(map_data);
	map_check(map_data->start_x, map_data->start_y, map_data);
}
