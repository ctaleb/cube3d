/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 11:01:22 by ctaleb            #+#    #+#             */
/*   Updated: 2020/12/21 11:49:00 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_nbrlen(unsigned long long nb)
{
	unsigned int	size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

char				*ft_utoa(unsigned int n)
{
	unsigned int		size;
	char				*nbr;
	unsigned long long	nb;

	size = ft_nbrlen(n);
	if (!(nbr = ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	nb = n;
	size--;
	if (nb == 0)
		nbr[size] = 48;
	while (nb != 0)
	{
		nbr[size] = nb % 10 + 48;
		nb /= 10;
		size--;
	}
	return (nbr);
}
