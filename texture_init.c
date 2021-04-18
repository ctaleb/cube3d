/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:50:06 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/18 13:14:44 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	texture_check(t_mlx_params *mlx)
{
	mem_check(mlx->n_txt->ptr, mlx, 13, -1);
	mlx->defined->north += 1;
	mem_check(mlx->s_txt->ptr, mlx, 13, -1);
	mlx->defined->south += 1;
	mem_check(mlx->e_txt->ptr, mlx, 13, -1);
	mlx->defined->east += 1;
	mem_check(mlx->w_txt->ptr, mlx, 13, -1);
	mlx->defined->west += 1;
}

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
	texture_check(mlx);
	mlx->n_txt->addr = (int *)mlx_get_data_addr(mlx->n_txt->ptr,
			&mlx->n_txt->bpp, &mlx->n_txt->len, &mlx->n_txt->endian);
	mlx->s_txt->addr = (int *)mlx_get_data_addr(mlx->s_txt->ptr,
			&mlx->s_txt->bpp, &mlx->s_txt->len, &mlx->s_txt->endian);
	mlx->e_txt->addr = (int *)mlx_get_data_addr(mlx->e_txt->ptr,
			&mlx->e_txt->bpp, &mlx->e_txt->len, &mlx->e_txt->endian);
	mlx->w_txt->addr = (int *)mlx_get_data_addr(mlx->w_txt->ptr,
			&mlx->w_txt->bpp, &mlx->w_txt->len, &mlx->w_txt->endian);
}

static void	bonus_textures(t_mlx_params *mlx)
{
	if (mlx->defined->skybox)
		mlx->skybox = texturer(mlx, mlx->map->skybox_t, &mlx->defined->skybox);
	if (mlx->defined->healthbar)
		mlx->healthbar = texturer(mlx, mlx->map->healthbar_t, &mlx->defined->healthbar);
	if (mlx->defined->ending)
		mlx->ending = texturer(mlx, mlx->map->ending_t, &mlx->defined->ending);
	if (mlx->defined->gameover)
		mlx->gameover = texturer(mlx, mlx->map->gameover_t, &mlx->defined->gameover);
	if (mlx->defined->cdoor)
		mlx->cdoor = texturer(mlx, mlx->map->cdoor_t, &mlx->defined->cdoor);
}

void	texture_init(t_mlx_params *mlx)
{
	mlx->n_txt = malloc(sizeof(t_texture));
	mem_check(mlx->n_txt, mlx, 2, mlx->stage);
	mlx->s_txt = malloc(sizeof(t_texture));
	mem_check(mlx->s_txt, mlx, 2, mlx->stage);
	mlx->e_txt = malloc(sizeof(t_texture));
	mem_check(mlx->e_txt, mlx, 2, mlx->stage);
	mlx->w_txt = malloc(sizeof(t_texture));
	mem_check(mlx->w_txt, mlx, 2, mlx->stage);
	texture_convert(mlx);
	bonus_textures(mlx);
}
