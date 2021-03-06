/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:55:21 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/26 13:32:02 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

float	dist_calc(float x, float y)
{
	return (sqrtf(powf(x, 2) + powf(y, 2)));
}

float	ft_dist(float x1, float y1, float x2, float y2)
{
	return (sqrtf(powf(x2 - x1, 2) + powf(y2 - y1, 2)));
}

int	anglizer(float vx1, float vy1, float vx2, float vy2)
{
	float	determinant;

	determinant = vx1 * vy2 - vx2 * vy1;
	if (determinant >= 0)
		return (1);
	else
		return (-1);
}
