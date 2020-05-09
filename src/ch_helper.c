/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 06:24:37 by scoron            #+#    #+#             */
/*   Updated: 2020/05/09 19:02:42 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ps_already_exist(t_pile *v, int int_arg)
{
	size_t		i;

	if (v->size != 0)
	{
		i = -1;
		while (++i < v->size)
		{
			if (*pile_get(v, i) == int_arg)
				return (1);
		}
	}
	return (0);
}

int				ps_is_int(char *str)
{
	int			sign;
	long long	res;

	res = 0;
	while (*str == ' ' || *str == '\f' || *str == '\t' || *str == '\r'
		|| *str == '\n' || *str == '\v')
		str++;
	if (*str == '-')
		sign = -1;
	else
		sign = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		res = res * 10 + (*str - '0');
		if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
			return (0);
		str++;
	}
	return (1);
}
