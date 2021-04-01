/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:28:59 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/01 13:34:35 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	rgbtoi(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	shader(t_mlx_params *mlx)
{
	int		i;
	float	x;
	float	j;
	float	step;

	i = 0;
	j = 0;
	x = 0;
	step = (mlx->map->res_y) / 510;
	while (i < (mlx->map->res_y) / 2)
	{
		mlx->f->shade[i] = trgbmod(mlx->map->ceiling_c, 1 - j * 0.0005);
		if (i++ % (mlx->map->res_y) / 10 == 0)
			x += 0.17;
		j += step * x;
	}	
	while (i < mlx->map->res_y)
	{
		mlx->f->shade[i] = trgbmod(mlx->map->floor_c, 1 - j * 0.0005);
		if (i++ % mlx->map->res_y / 10 == 0)
			x -= 0.17;
		j -= step * x;
	}
	while (i < mlx->map->res_y + 80)
		mlx->f->shade[i++] = mlx->map->floor_c;
}

int	trgbmod(int trgb, float factor)
{
	int		t;
	int		r;
	int		g;
	int		b;

	t = trgb & (255 << 24);
	r = (trgb & (255 << 16)) / 65536;
	g = (trgb & (255 << 8)) / 256;
	b = trgb & (255);
	r *= factor;
	if (r <= 0)
		r = 0;
	if (r > 256)
		r = 255;
	g *= factor;
	if (g <= 0)
		g = 0;
	if (g > 256)
		g = 255;
	b *= factor;
	if (b <= 0)
		b = 0;
	if (b > 256)
		b = 255;
	return (rgbtoi(t, r, g, b));
}
