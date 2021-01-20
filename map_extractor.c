/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extractor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:27:33 by ctaleb            #+#    #+#             */
/*   Updated: 2021/01/20 11:25:45 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	analyne(t_map *map_data, char *line)
{
	if (!data_check(map_data))
	{
		if (line[0] == 'R')
			get_resolution(map_data->size_x, map_data->size_y, &line[1]);
		else if (line[0] == 'F')
			get_colour(map_data->floor_c, line);
		else if (line[0] == 'C')
			get_colour(map_data->ceiling_c, line);
		else if (line[0] == 'S' && line[1] == ' ')
			get_path(map_data->sprite_t, &line[1]);
		else if (line[0] == 'N' && line[1] == 'O')
			get_path(map_data->north_t, &line[2]);
		else if (line[0] == 'S' && line [1] == 'O')
			get_path(map_data->south_t, &line[2]);
		else if (line[0] == 'E' && line[1] == 'A')
			get_path(map_data->east_t, &line[2]);
		else if (line[0] == 'W' && line[1] == 'E')
			get_path(map_data->west_t, &line[2]);
	}
	else
	{
	get_map(map_data->grid,line);
	}
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
	map_data->north_t = NULL;
	map_data->south_t = NULL;
	map_data->east_t = NULL;
	map_data->west_t = NULL;
	map_data->sprite_t = NULL;
}

t_map		*map_open(char *path)
{
	int		fd;
	char	*line;
	t_map	*map_data;

	map_data = malloc(sizeof(t_map));
	map_data_init(map_data);
	if ((fd = open(path, O_RDONLY)) < 0)
		error_handler(11);
	while (ft_get_next_line(fd, 10, &line))
	{
		analyne(map_data, line);
		free(line);
	}
	analyne(map_data, line);
	if (close(fd) < 0)
		error_handler(12);
	return (map_data);
}
