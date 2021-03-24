/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extractor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:27:33 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/24 13:05:01 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	is_map(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		if ((line[i] >= '0' && line[i] <= '2') || line[i] == ' '
			|| line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W')
			i++;
		else
			return (0);
	}
	if (i == 0)
		return (0);
	return (1);
}

int	analyne(t_map *map_data, char *line, t_mlx_params *mlx)
{
	if (!data_check(map_data))
	{
		if (line[0] == 'R')
			get_resolution(map_data, &line[1], mlx);
		else if (line[0] == 'F' && map_data->floor_c < 0)
			map_data->floor_c = get_colour(&line[1], mlx);
		else if (line[0] == 'C' && map_data->ceiling_c < 0)
			map_data->ceiling_c = get_colour(&line[1], mlx);
		else if (line[0] == 'S' && line[1] == ' ' && !map_data->sprite_t)
			map_data->sprite_t = get_path(&line[2], mlx);
		else if (line[0] == 'N' && line[1] == 'O' && !map_data->north_t)
			map_data->north_t = get_path(&line[2], mlx);
		else if (line[0] == 'S' && line[1] == 'O' && !map_data->south_t)
			map_data->south_t = get_path(&line[2], mlx);
		else if (line[0] == 'E' && line[1] == 'A' && !map_data->east_t)
			map_data->east_t = get_path(&line[2], mlx);
		else if (line[0] == 'W' && line[1] == 'E' && !map_data->west_t)
			map_data->west_t = get_path(&line[2], mlx);
	}
	else if (line[0] == '\0')
		return (0);
	else
		map_data->sprite_nb += get_map(map_data->grid, map_data->max_x, line);
	return (0);
}

void	map_open(char *path, t_mlx_params *mlx)
{
	int		fd;
	int		i;
	char	*line;

	mlx->map = malloc(sizeof(t_map));
	mem_check(mlx->map, mlx, 2, 1);
	map_data_init(mlx, path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_handler(11, mlx, 3);
	i = 0;
	while (ft_get_next_line(fd, 10, &line))
	{
		mlx->map->file[i] = ft_strdup(line);
		file_check(mlx->map->file[i], mlx, i);
		free(line);
		line = NULL;
		i++;
	}
	mlx->map->file[i] = ft_strdup(line);
	file_check(mlx->map->file[i], mlx, i);
	free(line);
	if (close(fd) < 0)
		error_handler(12, mlx, 4);
	map_init(mlx);
}
