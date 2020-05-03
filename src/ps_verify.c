/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_verify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 06:24:37 by scoron            #+#    #+#             */
/*   Updated: 2020/05/03 08:27:19 by scoron           ###   ########.fr       */
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
	long int	res;

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

int				ft_count_args(const char *str, char c)
{
	int			i;
	int			arg_count;
	int			flag;

	i = 0;
	arg_count = 0;
	flag = 0;
	while (str[i])
	{
		if (c == str[i])
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			arg_count++;
		}
		i++;
	}
	return (arg_count);
}

int				ps_parse_arg(t_pile *a, int i, int ac, char **av)
{
	int			int_arg;
	int			only_one;

	only_one = 0;
	if (ac - i == 1)
	{
		ac = ft_count_args(av[i], ' ');
		av = ft_strsplit(av[i], ' ');
		only_one = 1;
		i = 0;
	}
	while (i < ac)
	{
		int_arg = ft_atoi(av[i]);
		if ((int_arg == 0 && !ft_isdigit(av[i][0]) && av[i][1] != '0') ||
				ps_already_exist(a, int_arg) || !ps_is_int(av[i++]))
		{
			ft_dprintf(2, "Error\n");
			(only_one ? ft_strlst_free(av) : 0);
			return (-1);
		}
		pile_insert(a, &int_arg, 1, 0);
	}
	(only_one ? ft_strlst_free(av) : 0);
	return (1);
}
