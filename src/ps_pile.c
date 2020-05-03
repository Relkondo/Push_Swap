/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 06:21:17 by scoron            #+#    #+#             */
/*   Updated: 2020/05/03 13:22:09 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pile_addall(t_pile *self, void const *data, size_t datalen)
{
	if (pile_reserve(self, datalen))
		return (1);
	ft_memcpy(pile_end(self), data, pile_offset(datalen));
	self->size += datalen;
	return (0);
}

int		pile_insert(t_pile *self, void const *data, size_t dtlen, size_t index)
{
	if (self->size < index || pile_reserve(self, dtlen))
		return (1);
	ft_memmove(pile_get(self, index + dtlen),
			pile_get(self, index),
			pile_offset(self->size - index));
	ft_memcpy(pile_get(self, index),
			data,
			pile_offset(dtlen));
	self->size += dtlen;
	return (0);
}

void	pile_clear(t_pile *self)
{
	if (self->max > 0)
	{
		self->max = 0;
		self->size = 0;
		free(self->content);
	}
}

int		pile_resize(t_pile *self, size_t new_size)
{
	void	*tmp;

	if (!(tmp = malloc(new_size * sizeof(int))))
		return (1);
	if (self->size > new_size)
		self->size = new_size;
	ft_memcpy(tmp, self->content, self->size * sizeof(int));
	free(self->content);
	self->content = tmp;
	self->max = new_size;
	return (0);
}

int		pile_reserve(t_pile *self, size_t size)
{
	const size_t	total_size = size + self->size;
	size_t			new_size;

	if (total_size > self->max)
	{
		new_size = (self->max > 0 ? self->max : PILE_INITIAL_SIZE);
		while (new_size < total_size)
			new_size *= PILE_FACTOR;
		return (pile_resize(self, new_size));
	}
	return (0);
}
