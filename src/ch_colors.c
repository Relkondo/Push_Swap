/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 06:24:37 by scoron            #+#    #+#             */
/*   Updated: 2020/05/03 18:56:18 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_green(int pos, t_pile *p, char *msg)
{
	char	*res;

	res = ft_strnjoin(3, FMT_BGREEN, msg, FMT_OFF);
	ft_printf(res, *pile_get(p, pos));
	free(res);
}

void		print_blue(void)
{
	char	*res;

	res = ft_strnjoin(3, FMT_BLUE, "%6c %6c\n%6c %6c\n\n", FMT_OFF);
	ft_printf(res, '_', '_', 'a', 'b');
	free(res);
}

void		print_red(char *line)
{
	char	*res;

	res = ft_strnjoin(3, FMT_RED, "%s\n", FMT_OFF);
	ft_printf(res, line);
	free(res);
}
