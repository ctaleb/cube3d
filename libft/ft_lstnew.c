/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:23:57 by ctaleb            #+#    #+#             */
/*   Updated: 2020/11/28 12:55:03 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lstnew;

	if (!(lstnew = ft_calloc(1, sizeof(t_list))))
		return (NULL);
	lstnew->content = content;
	lstnew->next = NULL;
	return (lstnew);
}
