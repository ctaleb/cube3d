/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:30:10 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/18 13:41:01 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// void	free_file(t_mlx_params *mlx)
// {
// 	int	i;

// 	i = 0;
// 	while (i < mlx->map->file_len)
// 	{
// 		// printf("%i\n", i);
// 		free(mlx->file[i]);
// 		i++;
// 	}
// }

// void	free_matrix(t_mlx_params *mlx, int mode)
// {
// 	int	i;

// 	i = 0;
// 	if (mode == 0)
// 	{
// 		while (mlx->map->grid[i])
// 		{
// 			free(mlx->map->grid[i]);
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		while (mlx->map->dup[i])
// 		{
// 			free(mlx->map->dup[i]);
// 			i++;
// 		}	
// 	}
// }

// void	free_sp(t_mlx_params *mlx)
// {
// 	int	i;

// 	if (mlx->map->sprite_nb == 0)
// 		return ;
// 	i = 0;
// 	while (i < mlx->map->sprite_nb)
// 	{
// 		free(mlx->sp[i]);
// 		i++;
// 	}
// }







void	free_all(t_mlx_params *mlx, int stage)
{
	int i;
	
	(void)stage;
	i = mlx->stage;
	if (mlx->stage >= mlx->d_stage && mlx->d_stage)
	{
		if (mlx->defined->skybox > 1)
			mlx_destroy_image(mlx->ptr, mlx->skybox->ptr);
		if (mlx->defined->cdoor > 1)
			mlx_destroy_image(mlx->ptr, mlx->cdoor->ptr);
		if (mlx->defined->healthbar > 1)
			mlx_destroy_image(mlx->ptr, mlx->healthbar->ptr);
		if (mlx->defined->h_pickup > 1)
			mlx_destroy_image(mlx->ptr, mlx->h_pickup->ptr);
		if (mlx->defined->d_pickup > 1)
			mlx_destroy_image(mlx->ptr, mlx->d_pickup->ptr);
		if (mlx->defined->sec_sp > 1)
			mlx_destroy_image(mlx->ptr, mlx->sec_sp->ptr);
		if (mlx->defined->tp_a > 1)
			mlx_destroy_image(mlx->ptr, mlx->tp_a->ptr);
		if (mlx->defined->tp_b > 1)
			mlx_destroy_image(mlx->ptr, mlx->tp_b->ptr);
		if (mlx->defined->tp_c > 1)
			mlx_destroy_image(mlx->ptr, mlx->tp_c->ptr);
		if (mlx->defined->tp_d > 1)
			mlx_destroy_image(mlx->ptr, mlx->tp_d->ptr);
		if (mlx->defined->key_a > 1)
			mlx_destroy_image(mlx->ptr, mlx->key_a->ptr);
		if (mlx->defined->key_b > 1)
			mlx_destroy_image(mlx->ptr, mlx->key_b->ptr);
		if (mlx->defined->ending > 1)
			mlx_destroy_image(mlx->ptr, mlx->ending->ptr);
		if (mlx->defined->gameover > 1)
			mlx_destroy_image(mlx->ptr, mlx->gameover->ptr);
		if (mlx->defined->sprite > 1)
			mlx_destroy_image(mlx->ptr, mlx->sp_txt->ptr);
		if (mlx->defined->north > 1)
			mlx_destroy_image(mlx->ptr, mlx->n_txt->ptr);
		if (mlx->defined->south > 1)
			mlx_destroy_image(mlx->ptr, mlx->s_txt->ptr);
		if (mlx->defined->east > 1)
			mlx_destroy_image(mlx->ptr, mlx->e_txt->ptr);
		if (mlx->defined->west > 1)
			mlx_destroy_image(mlx->ptr, mlx->w_txt->ptr);
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
