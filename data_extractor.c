/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_extractor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:00:22 by ctaleb            #+#    #+#             */
/*   Updated: 2021/01/21 11:44:13 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		data_check(t_map *map_data)
{
	if (map_data->size_x && map_data->size_y && map_data->north_t
			&& map_data->south_t && map_data->east_t && map_data->west_t
			&& map_data->sprite_t && map_data->floor_c && map_data->ceiling_c)
		return (1);
	return (0);
}

int		get_colour(char *line)
{
	int i;
	int r;
	int g;
	int b;

	i = 0;
	if (line[i] != 'C' || line[i] != 'F')
		error_handler(21);
	i++;
	r = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i++] != ',')
		error_handler(21);
	g = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i++] != ',')
		error_handler(21);
	b = ft_atoi(&line[i]);
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		error_handler(22);
	return (rgbtoi(0, r, g, b));
}

char	*get_path(char *line)
{
	int i;
	int		j;
	char	*dest;

	i = 0;
	while (line[i] == ' ')
		i++;
	dest = malloc(sizeof(char) * (ft_strlen(&line[i]) + 1));
	j = 0;
	while (line[i + j])
	{
		if (ft_isspace(line[i]))
			error_handler(21);
		dest[j] = line[i + j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

void	get_resolution(t_map *map_data, char *line)
{
	int i;

	if (map_data->size_x >= 0 || map_data->size_y >= 0)
		error_handler(23);
	i = 0;
	while (line[i] == ' ')
		i++;
	map_data->size_x = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	map_data->size_y = ft_atoi(&line[i]);
	if (map_data->size_x > 5120 || map_data->size_y > 2880)
		error_handler(22);
}

void	get_map(int **grid, char *line)
{
	static int	i;
	int			j;

	j = 0;
	while(line[j])
	{
		if (line[j] == ' ')
			grid[i][j] = -1;
		else if (line[j] == '0')
			grid[i][j] = 0;
		else if (line[j] == '1')
			grid[i][j] = 1;
		else if (line[j] == '2')
			grid[i][j] = 2;
		else if (line[j] == 'N')
			grid[i][j] = 8;
		else if (line[j] == 'S')
			grid[i][j] = 5;
		else if (line[j] == 'E')
			grid[i][j] = 6;
		else if (line[j] == 'W')
			grid[i][j] = 4;
		j++;
	}
	i++;
}