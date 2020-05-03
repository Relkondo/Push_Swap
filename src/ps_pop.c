/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 06:21:32 by scoron            #+#    #+#             */
/*   Updated: 2020/05/03 07:48:22 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				pile_popback(t_pile *self, size_t len)
{
	self->size -= (len > self->size) ? self->size : len;
}

int					pile_popindex(t_pile *self, size_t index, size_t len)
{
	const size_t	n = (len > self->size - index) ? self->size - index : len;

	if (index > self->size)
		return (1);
	ft_memmove(pile_get(self, index),
			pile_get(self, index + n),
			pile_offset(self->size - n - index));
	self->size -= n;
	return (0);
}
