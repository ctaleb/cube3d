/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extractor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:27:33 by ctaleb            #+#    #+#             */
/*   Updated: 2021/01/21 16:26:40 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	analyne(t_map *map_data, char *line)
{
	if (!data_check(map_data))
	{
		if (line[0] == 'R')
			get_resolution(map_data, &line[1]);
		else if (line[0] == 'F' && map_data->floor_c < 0)
			map_data->floor_c = get_colour(line);
		else if (line[0] == 'C' && map_data->ceiling_c < 0)
			map_data->ceiling_c = get_colour(line);
		else if (line[0] == 'S' && line[1] == ' ' && !map_data->sprite_t)
			map_data->sprite_t = get_path(&line[2]);
		else if (line[0] == 'N' && line[1] == 'O' && !map_data->north_t)
				map_data->north_t = get_path(&line[2]);
		else if (line[0] == 'S' && line [1] == 'O' && !map_data->south_t)
			map_data->south_t = get_path(&line[2]);
		else if (line[0] == 'E' && line[1] == 'A' && !map_data->east_t)
			map_data->east_t = get_path(&line[2]);
		else if (line[0] == 'W' && line[1] == 'E' && !map_data->west_t)
			map_data->west_t = get_path(&line[2]);
	}
	else if (line[0] == '\0')
		return (0);
	else
		get_map(map_data->grid,line);
	return (0);
}

static void	map_data_init(t_map *map_data)
{
	map_data->grid = 0;
	map_data->valid = 0;
	map_data->size_x = 0;
	map_data->size_y = 0;
	map_data->floor_c = -1;
	map_data->ceiling_c = -1;
	map_data->grid_len = 0;

	map_data->north_t = NULL;
	map_data->south_t = NULL;
	map_data->east_t = NULL;
	map_data->west_t = NULL;
	map_data->sprite_t = NULL;
}

static int	is_map(char *line)
{
	int i;

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

static void	grid_init(t_map *map_data)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (!is_map(map_data->file[i]))
		i++;
	j = 0;
	while (is_map(map_data->file[i]))
	{
		temp = ft_strlen(map_data->file[i]);
		if (temp > map_data->grid_len)
			map_data->grid_len = temp;
		i++;
		j++;
	}
	map_data->grid = ft_calloc(j + 1, sizeof(int));
	i = 0;
	while (i < j)
	{
		map_data->grid[i] = ft_calloc(map_data->grid_len, sizeof(int));
		i++;
	}
}

t_map		*map_open(char *path)
{
	int		fd;
	int		i;
	char	*line;
	t_map	*map_data;

	map_data = malloc(sizeof(t_map));
	map_data_init(map_data);
	if ((fd = open(path, O_RDONLY)) < 0)
		error_handler(11);
	i = 0;
	while (ft_get_next_line(fd, 10, &line))
	{
		map_data->file[i] = line;
		line = NULL;
		i++;
	}
	grid_init(map_data);
	i = 0;
	while (map_data->file[i])
	{
		analyne(map_data, map_data->file[i]);
		i++;
	}
	if (close(fd) < 0)
		error_handler(12);
	return (map_data);
}
