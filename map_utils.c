/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:05:42 by ctaleb            #+#    #+#             */
/*   Updated: 2021/02/22 09:56:16 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	file_len(char *path)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_handler(11);
	i = 0;
	while (ft_get_next_line(fd, 10, &line))
	{
		free(line);
		i++;
	}
	i++;
	if (close(fd) < 0)
		error_handler(12);
	return (i);
}

void	start_check(t_map *map_data)
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
				if (map_data->start_x <= 0 && map_data->start_y <= 0)
				{
					map_data->start_x = j;
					map_data->start_y = i;
				}
				else
					error_handler(25);
			}
			j++;
		}
		i++;
	}
}

void	map_check(int x, int y, t_map *map_data)
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
		error_handler(26);
	if ((x == 0 && (y >= 0 && y < map_data->max_y))
		|| (x == map_data->max_x && (y >= 0 && y < map_data->max_y))
		|| (y == 0 && (x >= 0 && x < map_data->max_x))
		|| (y == map_data->max_y && (x >= 0 && x < map_data->max_x)))
		error_handler(26);
	map_data->dup[y][x] = 'o';
	map_check(x - 1, y - 1, map_data);
	map_check(x - 1, y, map_data);
	map_check(x - 1, y + 1, map_data);
	map_check(x, y + 1, map_data);
	map_check(x, y - 1, map_data);
	map_check(x + 1, y - 1, map_data);
	map_check(x + 1, y, map_data);
	map_check(x + 1, y + 1, map_data);
}

void	get_map(char **grid, int maxlen, char *line)
{
	static int	i;
	int			j;

	j = 0;
	while (line[j])
	{
		grid[i][j] = line[j];
		j++;
	}
	while (j < maxlen)
	{
		grid[i][j] = ' ';
		j++;
	}
	i++;
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
