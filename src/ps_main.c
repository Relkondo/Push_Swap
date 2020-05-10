/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 06:21:04 by scoron            #+#    #+#             */
/*   Updated: 2020/05/03 19:18:06 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			intro_parse(t_pile *a, t_pile *b, int argc, char **argv)
{
	if (ps_parse_arg(a, 1, argc, argv) == -1)
	{
		pile_clear(a);
		return (0);
	}
	if (ps_parse_arg(b, 1, argc, argv) == -1)
	{
		pile_clear(b);
		return (0);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_pile	a;
	t_pile	b;

	if (argc < 2)
		return (0);
	a = new_pile();
	b = new_pile();
	if (intro_parse(&a, &b, argc, argv) == 0)
		return (0);
	ps_sort(&b, 0, b.size - 1);
	ps_index(&a, &b);
	if (a.size > 5)
		ps_push_swap_init(&a, &b);
	else
		ps_push_swap_small(&a, &b);
	return (0);
}
