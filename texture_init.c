/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:50:06 by ctaleb            #+#    #+#             */
/*   Updated: 2021/02/25 10:17:21 by ctaleb           ###   ########lyon.fr   */
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
	mlx->n_txt->addr = (int *)mlx_get_data_addr(mlx->n_txt->ptr, &mlx->n_txt->bpp,
		&mlx->n_txt->len, &mlx->n_txt->endian);
	mlx->s_txt->addr = (int *)mlx_get_data_addr(mlx->s_txt->ptr, &mlx->s_txt->bpp,
		&mlx->s_txt->len, &mlx->s_txt->endian);
	mlx->e_txt->addr = (int *)mlx_get_data_addr(mlx->e_txt->ptr, &mlx->e_txt->bpp,
		&mlx->e_txt->len, &mlx->e_txt->endian);
	mlx->w_txt->addr = (int *)mlx_get_data_addr(mlx->w_txt->ptr, &mlx->w_txt->bpp,
		&mlx->w_txt->len, &mlx->w_txt->endian);
}

static void	texture_check(t_mlx_params *mlx)
{
	if (!mlx->n_txt->ptr)
		error_handler(13);
	if (!mlx->s_txt->ptr)
		error_handler(13);
	if (!mlx->e_txt->ptr)
		error_handler(13);
	if (!mlx->w_txt->ptr)
		error_handler(13);
}

void	texture_init(t_mlx_params *mlx)
{
	t_texture	*north_texture;
	t_texture	*south_texture;
	t_texture	*east_texture;
	t_texture	*west_texture;

	north_texture = malloc(sizeof(t_texture));
	if (!north_texture)
		error_handler(2);
	south_texture = malloc(sizeof(t_texture));
	if (!south_texture)
		error_handler(2);
	east_texture = malloc(sizeof(t_texture));
	if (!east_texture)
		error_handler(2);
	west_texture = malloc(sizeof(t_texture));
	if (!west_texture)
		error_handler(2);
	mlx->n_txt = north_texture;
	mlx->s_txt = south_texture;
	mlx->e_txt = east_texture;
	mlx->w_txt = west_texture;
	texture_convert(mlx);
	texture_check(mlx);
}
