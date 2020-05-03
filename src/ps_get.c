/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 06:20:36 by scoron            #+#    #+#             */
/*   Updated: 2020/05/03 08:19:26 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ps_get_size(t_pile *p, int limit)
{
	int		i;

	if (p->size == 0)
		return (0);
	i = 0;
	while (*pile_content(p, (int)p->size - 1 - i) <= limit &&
			*pile_content(p, (int)p->size - 1 - i) != 1)
		i++;
	return (i);
}

int			ps_get_average(t_pile *p)
{
	int		i;
	float	sum;

	if (p->size == 0)
		return (0);
	i = p->size;
	sum = 0;
	while (--i >= 0)
		sum += *pile_content(p, i);
	return ((int)(sum / (int)p->size + 0.5));
}

int			ps_get_average_section(t_pile *p, int top_value)
{
	int		i;
	float	sum;

	if (p->size == 0)
		return (0);
	i = 0;
	sum = 0;
	while (*pile_content(p, (int)p->size - 1 - i) <= top_value &&
			*pile_content(p, (int)p->size - 1 - i) != 1)
	{
		sum += *pile_content(p, (int)p->size - 1 - i);
		i++;
	}
	return ((int)(sum / i + 0.5));
}

int			ps_get_max(t_pile *p)
{
	size_t	i;
	int		max;

	if (p->size == 0)
		return (0);
	i = -1;
	max = 0;
	while (++i < p->size)
	{
		if (max < *pile_content(p, i))
			max = *pile_content(p, i);
	}
	return (max);
}

int			ps_get_min(t_pile *p)
{
	size_t	i;
	int		min;

	if (p->size == 0)
		return (0);
	min = *pile_content(p, 0);
	i = -1;
	while (++i < p->size)
	{
		if (min > *pile_content(p, i))
			min = *pile_content(p, i);
	}
	return (min);
}
