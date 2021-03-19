/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:50:06 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/19 10:46:58 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	texture_convert(t_mlx_params *mlx)
{
	mlx->n_txt->ptr = mlx_xpm_file_to_image(mlx->ptr, mlx->map->north_t,
			&mlx->n_txt->width, &mlx->n_txt->height);
	mlx->s_txt->ptr = mlx_xpm_file_to_image(mlx->ptr, mlx->map->south_t,
			&mlx->s_txt->width, &mlx->s_txt->height);
	mlx->e_txt->ptr = mlx_xpm_file_to_image(mlx->ptr, mlx->map->east_t,
			&mlx->e_txt->width, &mlx->e_txt->height);
	mlx->w_txt->ptr = mlx_xpm_file_to_image(mlx->ptr, mlx->map->west_t,
			&mlx->w_txt->width, &mlx->w_txt->height);
	mlx->n_txt->addr = (int *)mlx_get_data_addr(mlx->n_txt->ptr,
			&mlx->n_txt->bpp, &mlx->n_txt->len, &mlx->n_txt->endian);
	mlx->s_txt->addr = (int *)mlx_get_data_addr(mlx->s_txt->ptr,
			&mlx->s_txt->bpp, &mlx->s_txt->len, &mlx->s_txt->endian);
	mlx->e_txt->addr = (int *)mlx_get_data_addr(mlx->e_txt->ptr,
			&mlx->e_txt->bpp, &mlx->e_txt->len, &mlx->e_txt->endian);
	mlx->w_txt->addr = (int *)mlx_get_data_addr(mlx->w_txt->ptr,
			&mlx->w_txt->bpp, &mlx->w_txt->len, &mlx->w_txt->endian);
}

static void	texture_check(t_mlx_params *mlx)
{
	mem_check(mlx->n_txt->ptr, mlx, 13);
	mem_check(mlx->s_txt->ptr, mlx, 13);
	mem_check(mlx->e_txt->ptr, mlx, 13);
	mem_check(mlx->w_txt->ptr, mlx, 13);
}

void	texture_init(t_mlx_params *mlx)
{
	mlx->n_txt = malloc(sizeof(t_texture));
	mem_check(mlx->n_txt, mlx, 2);
	mlx->s_txt = malloc(sizeof(t_texture));
	mem_check(mlx->s_txt, mlx, 2);
	mlx->e_txt = malloc(sizeof(t_texture));
	mem_check(mlx->e_txt, mlx, 2);
	mlx->w_txt = malloc(sizeof(t_texture));
	mem_check(mlx->w_txt, mlx, 2);
	texture_convert(mlx);
	texture_check(mlx);
}
