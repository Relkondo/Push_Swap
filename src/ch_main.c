/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 06:15:13 by scoron            #+#    #+#             */
/*   Updated: 2020/05/09 21:00:25 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ch_parse_options(char **argv, t_pile *options)
{
	int			i;
	int			j;
	const char	*possible_options = "vca";
	int			k;
	int			data;

	k = 0;
	data = 0;
	while (possible_options[k++])
		pile_addall(options, &data, 1);
	i = 0;
	while (argv[++i] && ft_strlen(argv[i]) > 1 && argv[i][0] == '-')
	{
		j = 0;
		while (argv[i][++j])
			if ((k = exist_in(argv[i][j], possible_options)) != -1)
				*pile_get(options, k) = 1;
			else
				return (i);
	}
	return (i);
}

void			ch_operation(char *line, t_pile *a, t_pile *b)
{
	if (ft_strnequ(line, "sa", 3))
		ps_s(a, "");
	else if (ft_strnequ(line, "sb", 3))
		ps_s(b, "");
	else if (ft_strnequ(line, "ss", 3))
		ps_ss(a, b, "");
	else if (ft_strnequ(line, "pa", 3))
		ps_p(a, b, "");
	else if (ft_strnequ(line, "pb", 3))
		ps_p(b, a, "");
	else if (ft_strnequ(line, "ra", 3))
		ps_r(a, "");
	else if (ft_strnequ(line, "rb", 3))
		ps_r(b, "");
	else if (ft_strnequ(line, "rr", 3))
		ps_rr(a, b, "");
	else if (ft_strnequ(line, "rra", 4))
		ps_r_r(a, "");
	else if (ft_strnequ(line, "rrb", 4))
		ps_r_r(b, "");
	else if (ft_strnequ(line, "rrr", 4))
		ps_rrr(a, b, "");
}

int				ch_check_line(char *line)
{
	if (ft_strnequ(line, "sa", 3))
		return (1);
	else if (ft_strnequ(line, "sb", 3))
		return (1);
	else if (ft_strnequ(line, "ss", 3))
		return (1);
	else if (ft_strnequ(line, "pa", 3))
		return (1);
	else if (ft_strnequ(line, "pb", 3))
		return (1);
	else if (ft_strnequ(line, "ra", 3))
		return (1);
	else if (ft_strnequ(line, "rb", 3))
		return (1);
	else if (ft_strnequ(line, "rr", 3))
		return (1);
	else if (ft_strnequ(line, "rra", 4))
		return (1);
	else if (ft_strnequ(line, "rrb", 4))
		return (1);
	else if (ft_strnequ(line, "rrr", 4))
		return (1);
	else
		return (0);
}

static int		ch_handle_lines(t_pile *a, t_pile *b, t_pile *opt)
{
	char		*line;
	char		ope;
	int			check;

	line = NULL;
	while ((check = get_next_line_ps(0, &line)) != 0)
	{
		if (check == -1 || ch_check_line(line) == 0)
		{
			//ft_printf("check : %d\n", check);
			write(2, "Error\n", 6);
			free(line);
			return (-1);
		}
		ch_operation(line, a, b);
		if (*pile_get(opt, OPT_V))
		{
			*pile_get(opt, OPT_A) ? sleep(1) : 0;
			ope = *pile_get(opt, OPT_C) ? ch_code_ope(line) : 0;
			*pile_get(opt, OPT_C) ? print_red(line) : ft_printf("%s\n", line);
			ch_print_stacks(a, b, ope);
		}
		free(line);
	}
	free(line);
	return (0);
}

int				main(int argc, char **argv)
{
	t_pile		a;
	t_pile		b;
	t_pile		opt;
	int			check;

	check = 0;
	if (argc > 1)
	{
		a = new_pile();
		b = new_pile();
		opt = new_pile();
		check = ps_parse_arg(&a, ch_parse_options(argv, &opt), argc, argv);
		if (check == 1)
			if ((check = ch_handle_lines(&a, &b, &opt)) != -1)
			{
				if (b.size == 0 && ps_is_sorted(&a))
					ft_printf("OK\n");
				else
					ft_printf("KO\n");
			}
		pile_clear(&a);
		pile_clear(&b);
		pile_clear(&opt);
	}
	return (check);
}
