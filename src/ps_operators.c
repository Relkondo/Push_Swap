/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 06:21:09 by scoron            #+#    #+#             */
/*   Updated: 2020/05/03 08:21:32 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_r(t_pile *p, char *to_print)
{
	int inter;

	if (p->size == 0)
		return ;
	inter = *pile_content(p, p->size - 1);
	pile_popback(p, 1);
	pile_insert(p, &inter, 1, 0);
	if (*to_print)
		ft_printf("%s", to_print);
}

void	ps_r_r(t_pile *p, char *to_print)
{
	int inter;

	if (p->size == 0)
		return ;
	inter = *pile_content(p, 0);
	pile_addall(p, &inter, 1);
	pile_popindex(p, 0, 1);
	if (*to_print)
		ft_printf("%s", to_print);
}

void	ps_p(t_pile *receiver, t_pile *sender, char *to_print)
{
	int inter;

	if (sender->size == 0)
		return ;
	inter = *pile_content(sender, sender->size - 1);
	pile_popback(sender, 1);
	pile_addall(receiver, &inter, 1);
	if (*to_print)
		ft_printf("%s", to_print);
}

void	ps_s(t_pile *p, char *to_print)
{
	int inter;

	if (p->size < 2)
		return ;
	inter = *pile_content(p, p->size - 2);
	*pile_content(p, p->size - 2) = *pile_content(p, p->size - 1);
	*pile_content(p, p->size - 1) = inter;
	if (*to_print)
		ft_printf("%s", to_print);
}
