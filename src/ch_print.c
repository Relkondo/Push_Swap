/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 06:20:06 by scoron            #+#    #+#             */
/*   Updated: 2020/05/03 09:13:50 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char		ch_code_ope(char *l)
{
	char	fl;

	fl = exist_in('a', l) != -1 ? 0 : 2;
	fl += exist_in('b', l) != -1 ? 0 : 1;
	fl += exist_in('s', l) != -1 ? 10 : 0;
	fl += exist_in('p', l) != -1 ? 20 : 0;
	fl += exist_in('r', l) != -1 ? 30 : 0;
	fl += ft_strlen(l) > 2 ? 10 : 0;
	return (fl);
}

void		ch_color(char ope, int pos, t_pile *p, char *msg, int type)
{
	size_t si;

	si = p->size;
	if ((ope && ope % 10 != type && ((pos + 1 == (int)(si) && ope / 10 != 3) ||
					(pos == 0 && ope / 10 == 3) ||
					(pos + 2 == (int)(si) && ope / 10 == 1))))
		msg = ft_strnjoin(3, FMT_BGREEN, msg, FMT_OFF);
	ft_printf(msg, *pile_content(p, pos));
}

char		*ch_color2(char *color, char *msg)
{
    return ft_strnjoin(3, color, msg, FMT_OFF);
}

void		ch_print_stacks(t_pile *a, t_pile *b, char ope)
{
	int		div;
	int		i;
	int		j;

	div = (int)a->size - (int)(b->size);
	i = a->size == 0 ? 0 : (int)(a->size);
	j = b->size == 0 ? 0 : (int)(b->size);
	while (i >= 0 && j >= 0)
	{
		if (div >= 0 && i--)
            ch_color(ope, i, a, "%6d ", 2);
		else
			ft_printf("%6c ", ' ');
		if (div <= 0 && j--)
            ch_color(ope, j, b, "%6d\n", 1);
		else
			ft_printf("%6c\n", ' ');
		div -= div > 0 ? 1 : 0;
		div += div < 0 ? 1 : 0;
	}
	ft_printf(ch_color2(FMT_BLUE, "%6c %6c\n%6c %6c\n\n"), '_', '_', 'a', 'b');
}
