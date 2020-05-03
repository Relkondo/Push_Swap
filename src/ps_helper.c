/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 06:24:37 by scoron            #+#    #+#             */
/*   Updated: 2020/05/03 13:19:42 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile		new_pile(void)
{
	t_pile	newpile;

	newpile.size = 0;
	newpile.max = 0;
	newpile.content = NULL;
	return (newpile);
}

int			*pile_get(t_pile *p, size_t i)
{
	if (i > p->size)
		return (NULL);
	return ((int*)(p->content + i * sizeof(int)));
}

int			pile_offset(int i)
{
	return (i * sizeof(int));
}

int			*pile_end(t_pile *p)
{
	return ((p)->content + (p)->size * sizeof(int));
}
