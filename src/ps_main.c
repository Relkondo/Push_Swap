/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 06:21:04 by scoron            #+#    #+#             */
/*   Updated: 2020/05/03 06:21:06 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{

	t_pile		a;
	t_pile		b;
    int			    i;

	if (argc < 2)
        return (0);

    a = NEW_PILE;
    b = NEW_PILE;
    i = 1;
    if (ps_parse_arg(&a, i, argc, argv) == -1 || ps_parse_arg(&b, i, argc, argv) == -1)
    {
        pile_clear(&a);
        return (0);
    }
    ps_sort(&b, 0, b.size - 1);
    ps_index(&a, &b);
    if (a.size > 5)
        ps_push_swap_init(&a, &b);
    else
        ps_push_swap_small(&a, &b);
	return (0);
}
