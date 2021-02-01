/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:56:06 by ctaleb            #+#    #+#             */
/*   Updated: 2021/02/01 16:01:17 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_player	*pl_init(t_map *map_data)
{
	t_player	*pl_data;

	if (!(pl_data = malloc(sizeof(t_player))))
		error_handler(2);
	pl_data->x = map_data->start_x + 0.5;
	pl_data->y = map_data->start_y + 0.5;
	if (map_data->grid[map_data->start_y][map_data->start_x] == 'N')
	{
		pl_data->cam_x = 0;
		pl_data->cam_y = -2;
	}
	else if (map_data->grid[map_data->start_y][map_data->start_x] == 'S')
	{
		pl_data->cam_x = 0;
		pl_data->cam_y = 2;
	}
	else if (map_data->grid[map_data->start_y][map_data->start_x] == 'E')
	{
		pl_data->cam_x = 2;
		pl_data->cam_y = 0;
	}
	else if (map_data->grid[map_data->start_y][map_data->start_x] == 'W')
	{
		pl_data->cam_x = -2;
		pl_data->cam_y = 0;
	}
	pl_data->colour = rgbtoi(0, 255, 0, 0);
	return (pl_data);
}
