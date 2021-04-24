/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:30:10 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/23 13:25:20 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	free_mandatory(t_mlx_params *mlx)
{
	if (mlx->def->sprite > 1)
		mlx_destroy_image(mlx->ptr, mlx->sp_txt->ptr);
	if (mlx->def->north > 1)
		mlx_destroy_image(mlx->ptr, mlx->n_txt->ptr);
	if (mlx->def->south > 1)
		mlx_destroy_image(mlx->ptr, mlx->s_txt->ptr);
	if (mlx->def->east > 1)
		mlx_destroy_image(mlx->ptr, mlx->e_txt->ptr);
	if (mlx->def->west > 1)
		mlx_destroy_image(mlx->ptr, mlx->w_txt->ptr);
}

static void	free_bonus_sprites(t_mlx_params *mlx)
{
	if (mlx->def->h_pickup > 1)
		mlx_destroy_image(mlx->ptr, mlx->h_pickup->ptr);
	if (mlx->def->d_pickup > 1)
		mlx_destroy_image(mlx->ptr, mlx->d_pickup->ptr);
	if (mlx->def->sec_sp > 1)
		mlx_destroy_image(mlx->ptr, mlx->sec_sp->ptr);
	if (mlx->def->tp_a > 1)
		mlx_destroy_image(mlx->ptr, mlx->tp_a->ptr);
	if (mlx->def->tp_b > 1)
		mlx_destroy_image(mlx->ptr, mlx->tp_b->ptr);
	if (mlx->def->tp_c > 1)
		mlx_destroy_image(mlx->ptr, mlx->tp_c->ptr);
	if (mlx->def->tp_d > 1)
		mlx_destroy_image(mlx->ptr, mlx->tp_d->ptr);
	if (mlx->def->key_a > 1)
		mlx_destroy_image(mlx->ptr, mlx->key_a->ptr);
	if (mlx->def->key_b > 1)
		mlx_destroy_image(mlx->ptr, mlx->key_b->ptr);
}

static void	free_bonus_textures(t_mlx_params *mlx)
{
	if (mlx->def->skybox > 1)
		mlx_destroy_image(mlx->ptr, mlx->skybox->ptr);
	if (mlx->def->door > 1)
		mlx_destroy_image(mlx->ptr, mlx->door->ptr);
	if (mlx->def->hb > 1)
		mlx_destroy_image(mlx->ptr, mlx->healthbar->ptr);
	if (mlx->def->ending > 1)
		mlx_destroy_image(mlx->ptr, mlx->ending->ptr);
	if (mlx->def->go > 1)
		mlx_destroy_image(mlx->ptr, mlx->gameover->ptr);
}

void	free_all(t_mlx_params *mlx, int stage)
{
	int	i;

	if (stage == -9)
		return ;
	i = mlx->stage;
	if (mlx->stage >= mlx->d_stage && mlx->d_stage)
	{
		free_mandatory(mlx);
		free_bonus_sprites(mlx);
		free_bonus_textures(mlx);
	}
	if (mlx->stage >= mlx->w_stage + 1 && mlx->w_stage)
		mlx_destroy_image(mlx->ptr, mlx->img->ptr);
	while (i > 0)
	{
		free(mlx->memory[i]);
		i--;
	}
	if (mlx->stage >= mlx->w_stage && mlx->w_stage && !mlx->save)
		mlx_destroy_window(mlx->ptr, mlx->win);
}
