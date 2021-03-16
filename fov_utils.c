/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:28:38 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/16 12:57:33 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	step_init(float cam, float start, float pl)
{
	if (cam >= 0)
		return ((int)start + 1);
	else if (start == pl)
		return ((int)start);
	else
		return ((int)start - 1);
}