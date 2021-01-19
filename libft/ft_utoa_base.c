/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 11:00:49 by ctaleb            #+#    #+#             */
/*   Updated: 2020/12/21 11:49:25 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_nbrlen(unsigned long long nb, unsigned int blen)
{
	unsigned int	size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= blen;
		size++;
	}
	return (size);
}

char				*ft_utoa_base(unsigned long long n, char *base)
{
	unsigned int		size;
	char				*nbr;
	unsigned long long	nb;
	unsigned int		blen;

	blen = ft_strlen(base);
	size = ft_nbrlen(n, blen);
	if (!(nbr = ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	nb = n;
	size--;
	if (nb == 0)
		nbr[size] = 48;
	while (nb != 0)
	{
		nbr[size] = base[nb % blen];
		nb /= blen;
		size--;
	}
	return (nbr);
}
