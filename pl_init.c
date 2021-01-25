/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:56:06 by ctaleb            #+#    #+#             */
/*   Updated: 2021/01/25 15:58:02 by ctaleb           ###   ########lyon.fr   */
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
	return (pl_data);
}