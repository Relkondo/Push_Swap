/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_verify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 06:24:37 by scoron            #+#    #+#             */
/*   Updated: 2020/05/09 20:58:35 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_count_args(const char *str, char c)
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

char		**ch_split(char *to_split)
{
	if (to_split == NULL || *to_split == '\0')
		return (NULL);
	return (ft_strsplit(to_split, ' '));
}

int			ch_do_parse(t_pile *a, int i, char **av, int only_one)
{
	int			int_arg;

	int_arg = ft_atoi(av[i]);
	if ((int_arg == 0 && !ft_isdigit(av[i][0]) && av[i][1] != '0') ||
			ps_already_exist(a, int_arg) || !ps_is_int(av[i]))
	{
		write(2, "Error\n", 6);
		(only_one ? ft_strlst_free(av) : 0);
		return (-1);
	}
	pile_insert(a, &int_arg, 1, 0);
	return (1);
}

int			ps_parse_arg(t_pile *a, int i, int ac, char **av)
{
	int			only_one;
	int			ret;

	only_one = 0;
	ret = 1;
	if (ac - i == 1)
	{
		ac = ft_count_args(av[i], ' ');
		only_one = 1;
		if ((av = ch_split(av[i])) == NULL)
			ret = 0;
		i = 0;
	}
	while (i < ac)
	{
		if (ch_do_parse(a, i, av, only_one) == -1)
			return (-1);
		i++;
	}
	(only_one ? ft_strlst_free(av) : 0);
	return (ret);
}
