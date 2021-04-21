/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:09:09 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/26 13:13:15 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

float	rad_deg(float rad)
{
	return (rad * 180 / M_PI);
}

float	deg_rad(float deg)
{
	return (deg * M_PI / 180);
}
