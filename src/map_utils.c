/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:05:42 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/28 17:11:08 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	file_len(char *path, t_mlx_params *mlx)
{
	int		fd;
	int		i;
	char	*line;

	if (ft_strncmp(&path[ft_strlen(path) - 4], ".cub", 5))
		error_handler(4, mlx, 2);
	fd = open(path, O_RDWR);
	if (fd < 0)
		error_handler(11, mlx, 2);
	i = 0;
	while (ft_get_next_line(fd, 10, &line))
	{
		free(line);
		i++;
	}
	free(line);
	i++;
	if (close(fd) < 0)
		error_handler(12, mlx, 2);
	return (i);
}

void	start_check(t_map *map_data, t_mlx_params *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (map_data->grid[i])
	{
		j = 0;
		while (map_data->grid[i][j])
		{
			if (map_data->grid[i][j] == 'N' || map_data->grid[i][j] == 'S'
				|| map_data->grid[i][j] == 'E' || map_data->grid[i][j] == 'W')
			{
				if (map_data->start_x < 0 && map_data->start_y < 0)
				{
					map_data->start_x = j;
					map_data->start_y = i;
				}
				else
					error_handler(25, mlx, 7);
			}
			j++;
		}
		i++;
	}
}

void	map_check(int x, int y, t_map *map_data, t_mlx_params *mlx)
{
	if (x >= map_data->max_x || y >= map_data->max_y)
		return ;
	if (x < 0 || y < 0)
		return ;
	if (map_data->dup[y][x] == '1')
		return ;
	if (map_data->dup[y][x] == 'o')
		return ;
	if (map_data->dup[y][x] == ' ')
		error_handler(26, mlx, 7);
	if ((x == 0 && (y >= 0 && y < map_data->max_y - 1))
		|| (x == map_data->max_x - 1 && (y >= 0 && y < map_data->max_y - 1))
		|| (y == 0 && (x >= 0 && x < map_data->max_x - 1))
		|| (y == map_data->max_y - 1 && (x >= 0 && x < map_data->max_x - 1)))
		error_handler(26, mlx, 7);
	map_data->dup[y][x] = 'o';
	map_check(x - 1, y - 1, map_data, mlx);
	map_check(x - 1, y, map_data, mlx);
	map_check(x - 1, y + 1, map_data, mlx);
	map_check(x, y + 1, map_data, mlx);
	map_check(x, y - 1, map_data, mlx);
	map_check(x + 1, y - 1, map_data, mlx);
	map_check(x + 1, y, map_data, mlx);
	map_check(x + 1, y + 1, map_data, mlx);
}

int	get_map(char **grid, int maxlen, char *line)
{
	static int	i;
	int			j;
	int			sprite_nb;

	j = 0;
	sprite_nb = 0;
	while (line[j])
	{
		grid[i][j] = line[j];
		if (line[j] == '2' || line[j] == '4' || line[j] == '5'
			|| line[j] == '6' || line[j] == '9' || line[j] == 'K')
			sprite_nb++;
		j++;
	}
	while (j < maxlen)
	{
		grid[i][j] = ' ';
		j++;
	}
	i++;
	return (sprite_nb);
}

void	dup_map(char **grid, char **dup)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			dup[i][j] = grid[i][j];
			j++;
		}
		i++;
	}
}
