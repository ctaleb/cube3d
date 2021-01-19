/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:03:04 by ctaleb            #+#    #+#             */
/*   Updated: 2020/11/28 17:53:02 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	nb;
	int					i;
	int					sym;

	i = 0;
	sym = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sym = (str[i] == '-') ? (-1) : (1);
		i++;
	}
	nb = 0;
	while (ft_isdigit(str[i]))
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	if (nb > 9223372036854775807)
		return (sym > 0) ? (-1) : (0);
	return (nb * sym);
}
