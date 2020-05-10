/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 06:20:49 by scoron            #+#    #+#             */
/*   Updated: 2020/05/10 01:55:00 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_sort_swapping(t_pile *p, int left, int right, int middle)
{
	int		inter;

	while (left <= right)
	{
		while (*pile_get(p, right) < middle)
			right--;
		while (*pile_get(p, left) > middle)
			left++;
		if (right >= left)
		{
			inter = *pile_get(p, right);
			*pile_get(p, right) = *pile_get(p, left);
			*pile_get(p, left) = inter;
			right--;
			left++;
		}
	}
	return (left);
}

int			ps_is_sorted(t_pile *p)
{
	int		i;

	if (p->size == 0)
		return (1);
	i = p->size;
	while (--i > 0)
	{
		if (*pile_get(p, i - 1) < *pile_get(p, i))
			return (0);
	}
	return (1);
}

void		ps_sort(t_pile *p, int left, int right)
{
	int		index;
	int		middle;

	if (left < right)
	{
		middle = *pile_get(p, (right + left) / 2);
		index = ps_sort_swapping(p, left, right, middle);
		ps_sort(p, left, index - 1);
		ps_sort(p, index, right);
	}
}

void		ps_index(t_pile *a, t_pile *b)
{
	int		i;
	int		j;

	i = (int)a->size - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < (int)b->size - 1)
		{
			if (*pile_get(a, i) == *pile_get(b, (int)b->size - 1 - j) &&
					*pile_get(b, (int)b->size - 1 - j) != 0x7FFFFFFF)
			{
				*pile_get(b, (int)b->size - 1 - j) = 0x7FFFFFFF;
				break ;
			}
			j++;
		}
		*pile_get(a, i) = j + 1;
		i--;
	}
	pile_clear(b);
	*b = new_pile();
}
