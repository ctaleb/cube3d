/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:55:21 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/07 16:38:35 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// float	dist_calc(float x, float y)
// {
// 	return (sqrtf(powf(x, 2) + powf(y, 2)));
// }

int	anglizer(float vx1, float vy1, float vx2, float vy2)
{
	int determinant;

	determinant = vx1 * vy2 - vx2 * vy1;
	if (determinant >= 0)
		return (1);
	else
		return (-1);
}

int	angler(float alpha, float beta)
{
	if (alpha - beta < 90)
	{
		
	}
	return (0);
}