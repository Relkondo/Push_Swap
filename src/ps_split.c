/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 06:24:26 by scoron            #+#    #+#             */
/*   Updated: 2020/05/03 06:24:34 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ps_max_btoa(t_pile *a, t_pile *b)
{
    if (ps_get_max(b) == PILE_CONTENT(b, b->size - 1))
        ps_p(a, b, "pa\n");
    else
    {
        if (PILE_CONTENT(b, b->size - 1) == PILE_CONTENT(a, 0) + 1 ||
            PILE_CONTENT(b, b->size - 1) == 1)
        {
            ps_p(a, b, "pa\n");
            ps_r(a, "ra\n");
        }
        else
            ps_rotation_b(b);
    }
}

void ps_split_btoa(t_pile *a, t_pile *b, int average, int size)
{
	while (size-- > 0)
	{
		if (b->size < 13)
            ps_max_btoa(a, b);
		else
		{
			if (average <= PILE_CONTENT(b, b->size - 1))
                ps_p(a, b, "pa\n");
			else
			{
				if (PILE_CONTENT(b, b->size - 1) == PILE_CONTENT(a, 0) + 1 ||
                    PILE_CONTENT(b, b->size - 1) == 1)
				{
                    ps_p(a, b, "pa\n");
                    ps_r(a, "ra\n");
				}
				else
                    ps_r(b, "rb\n");
			}
		}
	}
}

void ps_split_atob(t_pile *a, t_pile *b, int average, int size)
{
	int i;

	i = -1;
	while (++i < size)
	{
		if (average > PILE_CONTENT(a, a->size - 1))
            ps_p(b, a, "pb\n");
		else
            ps_r(a, "ra\n");
	}
}

void ps_rotation_b(t_pile *b)
{
    int i;

    i = -1;
    while (++i < (int)b->size)
        if (PILE_CONTENT(b, i) == ps_get_max(b))
            break ;
    if (i <= (int)b->size / 2)
        ps_r_r(b, "rrb\n");
    else
        ps_r(b, "rb\n");
}


