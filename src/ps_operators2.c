/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operators2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 06:21:14 by scoron            #+#    #+#             */
/*   Updated: 2020/05/03 07:46:53 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rr(t_pile *p1, t_pile *p2, char *to_print)
{
	ps_r(p1, "");
	ps_r(p2, "");
	if (*to_print)
		ft_printf("%s", "rr\n");
}

void	ps_ss(t_pile *p1, t_pile *p2, char *to_print)
{
	ps_s(p1, "");
	ps_s(p2, "");
	if (*to_print)
		ft_printf("%s", "ss\n");
}

void	ps_rrr(t_pile *p1, t_pile *p2, char *to_print)
{
	ps_r_r(p1, "");
	ps_r_r(p2, "");
	if (*to_print)
		ft_printf("%s", "rrr\n");
}
