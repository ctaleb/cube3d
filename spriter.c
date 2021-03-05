/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spriter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:14:24 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/04 11:10:13 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// void	put_sprite(int i, t_texture *texture, t_mlx_params *mlx)
// {
// 	int	y;
// 	int	tex_x;
// 	int	tex_y;
	
// 	y = 0;
// 	while (y < mlx->map->res_y)
// 	{

// 	}
// }

void	sprite_check(t_mlx_params *mlx)
{
	int	i;
	int	t_x;
	int	t_y;

	sprites_sort(mlx);
	i = 0;
	while (i < mlx->map->sprite_nb)
	{
		sprite_xpos(i, mlx);
		// t_x = mlx->f->cam_y * mlx->sp[i]->r_x - mlx->pl->x - mlx->f->cam_x * mlx->sp[i]->r_y - mlx->pl->y;
		// t_y = mlx->sp[i]->r_y - mlx->pl->y;
		i++;
	}
// 	// printf("r_angle%f\n", r_angle);
// 	while (i < mlx->map->sprite_nb - 1)
// 	{
// 		// printf("%i\t%f\t%f\n", i, mlx->sp[i]->l_angle, mlx->sp[i]->h_angle);
// 		while (i)
// 		{
// 			put_sprite(i, mlx->sp_txt, mlx);
// 		}
// 		i++;
// 	}
// 	// printf("\n");
// 	// getchar();
// 	// put_sprite(mlx->sp_txt, mlx);
}