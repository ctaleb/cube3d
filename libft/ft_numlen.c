/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:27:45 by ctaleb            #+#    #+#             */
/*   Updated: 2020/12/19 11:14:04 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlen(const char *str)
{
	size_t size;
	size_t digit;

	size = 0;
	digit = 0;
	while (str[size])
	{
		if (ft_ishex(str[size]))
			digit++;
		size++;
	}
	return (digit);
}
