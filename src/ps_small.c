/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_small.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 06:24:10 by scoron            #+#    #+#             */
/*   Updated: 2020/05/03 06:24:24 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ps_small_sort(t_pile *p, int is_a)
{
    int	i;

    if (p->size == 0)
        return ;
    i = p->size;
    while (--i > 0)
    {
        if (PILE_CONTENT(p, p->size - 1 - is_a) == ps_get_min(p) &&
            PILE_CONTENT(p, p->size - 2 + is_a) == ps_get_max(p))
            is_a ? ps_r(p, "ra\n") : ps_r(p, "rb\n");
        if (PILE_CONTENT(p, i - 1) * (-2 * is_a + 1) > PILE_CONTENT(p, i) * (-2 * is_a + 1))
        {
            while (i++ < (int)p->size - 1)
                is_a ? ps_r(p, "ra\n") : ps_r(p, "rb\n");
            i--;
            if (PILE_CONTENT(p, p->size - 1 - is_a) == ps_get_min(p) &&
                PILE_CONTENT(p, p->size - 2 + is_a) == ps_get_max(p))
                is_a ? ps_r(p, "ra\n") : ps_r(p, "rb\n");
            else
                is_a ? ps_s(p, "sa\n") : ps_s(p, "sb\n");
        }
    }
}

void ps_small_rotate_a(t_pile *a)
{
	int i;

	i = -1;
	while (++i < (int)a->size)
		if (PILE_CONTENT(a, i) == ps_get_min(a))
			break ;
	if (i <= (int)a->size / 2)
        ps_r_r(a, "rra\n");
	else
        ps_r(a, "ra\n");
}

void ps_small_split(t_pile *a, t_pile *b)
{
	int average;

    average = ps_get_average(a);
	while (ps_get_min(a) < average)
	{
		if (PILE_CONTENT(a, a->size - 1) < average)
		{
			if (PILE_CONTENT(a, 0) + 1 == PILE_CONTENT(a, a->size - 1))
			{
                ps_small_rotate_a(a);
				if (ps_is_sorted(a))
					return ;
			}
            ps_p(b, a, "pb\n");
		}
		else
		{
            ps_small_rotate_a(a);
		}
	}
}
