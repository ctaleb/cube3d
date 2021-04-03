/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extractor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:27:33 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/03 11:18:57 by ctaleb           ###   ########lyon.fr   */
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
		if ((line[i] >= '0' && line[i] <= '3') || line[i] == ' '
			|| line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W' || line[i] == '3')
			i++;
		else
			return (0);
	}
	if (i == 0)
		return (0);
	return (1);
}

int	analyne(t_map *map_data, char *line)
{
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
