/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extractor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:27:33 by ctaleb            #+#    #+#             */
/*   Updated: 2021/05/08 14:20:56 by ctaleb           ###   ########lyon.fr   */
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
		if ((line[i] >= '0' && line[i] <= '9') || line[i] == ' '
			|| line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W' || line[i] == 'K')
			i++;
		else
			return (0);
	}
	if (i == 0)
		return (0);
	return (1);
}

int	read_cub(t_mlx_params *mlx)
{
	int	i;

	i = 0;
	while (!data_check(mlx->map) && !is_map(mlx->file[i]))
	{
		if (!mlx->file[i])
			error_handler(22, mlx, 4);
		read_mandatory(i, mlx);
		read_textures(i, mlx);
		read_bonus_sprites(i, mlx);
		read_bonus_textures(i, mlx);
		read_bonus_teleporter(i, mlx);
		read_bonus_info(i, mlx);
		read_music(i, mlx);
		unvalidator(i, mlx);
		i++;
	}
	return (i);
}

int	analyne(t_map *map_data, char *line)
{
	map_data->sprite_nb += get_map(map_data->grid, map_data->max_x, line);
	return (0);
}

void	read_textures(int i, t_mlx_params *mlx)
{
	if (mlx->file[i][0] == 'S' && mlx->file[i][1] != 'O')
	{
		mlx->map->sp_t = get_path(&mlx->file[i][1], mlx->map->sp_t, mlx, 1);
		mlx->def->sprite = 1;
	}
	else if (mlx->file[i][0] == 'N' && mlx->file[i][1] == 'O')
	{
		mlx->map->north = get_path(&mlx->file[i][2], mlx->map->north, mlx, 1);
		mlx->def->north = 1;
	}
	else if (mlx->file[i][0] == 'S' && mlx->file[i][1] == 'O')
	{
		mlx->map->south = get_path(&mlx->file[i][2], mlx->map->south, mlx, 1);
		mlx->def->south = 1;
	}
	else if (mlx->file[i][0] == 'E' && mlx->file[i][1] == 'A')
	{
		mlx->map->east = get_path(&mlx->file[i][2], mlx->map->east, mlx, 1);
		mlx->def->east = 1;
	}
	else if (mlx->file[i][0] == 'W' && mlx->file[i][1] == 'E')
	{
		mlx->map->west = get_path(&mlx->file[i][2], mlx->map->west, mlx, 1);
		mlx->def->west = 1;
	}
}

void	map_open(char *path, t_mlx_params *mlx)
{
	int		fd;
	int		i;
	char	*line;

	mlx->map = malloc(sizeof(t_map));
	mem_check(mlx->map, mlx, 2, 1);
	map_data_init(mlx, path);
	fd = open(path, O_RDWR);
	if (fd < 0)
		error_handler(11, mlx, 3);
	i = 0;
	while (ft_get_next_line(fd, 10, &line))
	{
		mlx->file[i] = ft_strdup(line);
		mem_check(mlx->file[i], mlx, 2, mlx->stage);
		free(line);
		line = NULL;
		i++;
	}
	mlx->file[i] = ft_strdup(line);
	mem_check(mlx->file[i], mlx, 2, mlx->stage);
	free(line);
	if (close(fd) < 0)
		error_handler(12, mlx, 4);
	map_init(mlx);
}
