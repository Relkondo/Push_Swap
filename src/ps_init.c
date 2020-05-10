/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 06:20:59 by scoron            #+#    #+#             */
/*   Updated: 2020/05/03 07:45:31 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_push_swap_init(t_pile *a, t_pile *b)
{
	if (ps_is_sorted(a))
	{	
		pile_clear(a);
		pile_clear(b);
		return ;
	}
	ps_split_atob(a, b, ps_get_average(a), a->size);
	ps_push_swap(a, b);
	if (ps_get_size(a, ps_get_max(a)) >= 20)
	{
		ps_roll_back_and_forth(a, b, ps_get_max(a));
		ps_roll_back_and_forth(a, b, ps_get_max(a));
	}
	ps_roll(a, b, ps_get_max(a));
	pile_clear(a);
	pile_clear(b);
}

void	ps_push_swap_small(t_pile *a, t_pile *b)
{
	if (ps_is_sorted(a))
	{	
		pile_clear(a);
		pile_clear(b);
		return ;
	}
	if (a->size > 4)
		ps_small_split(a, b);
	ps_small_sort(a, 1);
	ps_small_sort(b, 0);
	while (b->size > 0)
		ps_p(a, b, "pa\n");
	pile_clear(a);
	pile_clear(b);
}
