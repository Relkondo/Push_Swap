/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 06:24:37 by scoron            #+#    #+#             */
/*   Updated: 2020/05/03 18:37:59 by scoron           ###   ########.fr       */
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

void		join_print(int pos, t_pile *p, char *msg, char *color)
{
	char *res;

	res = ft_strnjoin(3, color, msg, FMT_OFF);
	ft_printf(res, *pile_get(p, pos));
	free(res);
}
