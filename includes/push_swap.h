/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 06:29:12 by scoron            #+#    #+#             */
/*   Updated: 2020/05/03 13:26:12 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# define OPT_V 0
# define OPT_C 1
# define OPT_A 2
# define PILE_INITIAL_SIZE 16
# define PILE_FACTOR 2

# define FMT_OFF "\033[0m"
# define FMT_BLACK "\033[0;30m"
# define FMT_RED "\033[0;31m"
# define FMT_GREEN "\033[0;32m"
# define FMT_YELLOW "\033[0;33m"
# define FMT_BLUE "\033[0;34m"
# define FMT_PURPLE "\033[0;35m"
# define FMT_CYAN "\033[0;36m"
# define FMT_WHITE "\033[0;37m"
# define FMT_BBLACK "\033[1;30m"
# define FMT_BRED "\033[1;31m"
# define FMT_BGREEN "\033[1;32m"
# define FMT_BYELLOW "\033[1;33m"
# define FMT_BBLUE "\033[1;34m"
# define FMT_BPURPLE "\033[1;35m"
# define FMT_BCYAN "\033[1;36m"
# define FMT_BWHITE "\033[1;37m"
# define FMT_UBLACK "\033[4;30m"
# define FMT_URED "\033[4;31m"
# define FMT_UGREEN "\033[4;32m"
# define FMT_UYELLOW "\033[4;33m"
# define FMT_UBLUE "\033[4;34m"
# define FMT_UPURPLE "\033[4;35m"
# define FMT_UCYAN "\033[4;36m"
# define FMT_UWHITE "\033[4;37m"
# define FMT_ON_BLACK "\033[40m"
# define FMT_ON_RED "\033[41m"
# define FMT_ON_GREEN "\033[42m"
# define FMT_ON_YELLOW "\033[43m"
# define FMT_ON_BLUE "\033[44m"
# define FMT_ON_PURPLE "\033[45m"
# define FMT_ON_CYAN "\033[46m"
# define FMT_ON_WHITE "\033[47m"
# define FMT_IBLACK "\033[0;90m"
# define FMT_IRED "\033[0;91m"
# define FMT_IGREEN "\033[0;92m"
# define FMT_IYELLOW "\033[0;93m"
# define FMT_IBLUE "\033[0;94m"
# define FMT_IPURPLE "\033[0;95m"
# define FMT_ICYAN "\033[0;96m"
# define FMT_IWHITE "\033[0;97m"
# define FMT_BIBLACK "\033[1;90m"
# define FMT_BIRED "\033[1;91m"
# define FMT_BIGREEN "\033[1;92m"
# define FMT_BIYELLOW "\033[1;93m"
# define FMT_BIBLUE "\033[1;94m"
# define FMT_BIPURPLE "\033[1;95m"
# define FMT_BICYAN "\033[1;96m"
# define FMT_BIWHITE "\033[1;97m"
# define FMT_ON_IBLACK "\033[0;100m"
# define FMT_ON_IRED "\033[0;101m"
# define FMT_ON_IGREEN "\033[0;102m"
# define FMT_ON_IYELLOW "\033[0;103m"
# define FMT_ON_IBLUE "\033[0;104m"
# define FMT_ON_IPURPLE "\033[10;95m"
# define FMT_ON_ICYAN "\033[0;106m"
# define FMT_ON_IWHITE "\033[0;107m"

typedef struct	s_pile
{
	void		*content;
	size_t		size;
	size_t		max;
}				t_pile;

void			ps_s(t_pile *p, char *to_print);
void			ps_p(t_pile *receiver, t_pile *sender, char *to_print);
void			ps_r(t_pile *p, char *to_print);
void			ps_r_r(t_pile *p, char *to_print);
void			ps_rrr(t_pile *p1, t_pile *p2, char *to_print);
void			ps_rotation_b(t_pile *b);
void			ps_ss(t_pile *p1, t_pile *p2, char *to_print);
void			ps_rr(t_pile *p1, t_pile *p2, char *to_print);
void			ps_push_swap_small(t_pile *a, t_pile *b);
void			ps_push_swap_init(t_pile *a, t_pile *b);
void			ps_roll_back_and_forth(t_pile *a, t_pile *b, int top_value);
void			ps_roll(t_pile *a, t_pile *b, int top_value);
void			ps_split_atob(t_pile *a, t_pile *b, int average, int size);
void			ps_split_btoa(t_pile *a, t_pile *b, int average, int size);
char			ch_code_ope(char *l);
void			ch_print_stacks(t_pile *a, t_pile *b, char ope);
int				ps_parse_arg(t_pile *a, int i, int ac, char **av);
void			ps_push_swap(t_pile *a, t_pile *b);
int				ps_get_min(t_pile *p);
int				ps_get_max(t_pile *p);
int				ps_get_average(t_pile *p);
int				ps_is_sorted(t_pile *p);
int				ch_parse_options(char **argv, t_pile *options);
int				ps_get_size(t_pile *p, int limit);
int				ps_get_average_section(t_pile *p, int top_value);
void			ps_index(t_pile *a, t_pile *b);
void			ps_sort(t_pile *p, int left, int right);
void			ps_small_sort(t_pile *p, int is_a);
void			ps_small_rotate_a(t_pile *a);
void			ps_small_split(t_pile *a, t_pile *b);
int				pile_resize(t_pile *self, size_t new_size);
void			pile_clear(t_pile *self);
int				pile_addall(t_pile *self, void const *data, size_t datalen);
int				pile_insert(t_pile *self, void const *data,
				size_t dtlen, size_t index);
int				pile_reserve(t_pile *self, size_t size);
void			pile_popback(t_pile *self, size_t len);
int				pile_popindex(t_pile *self, size_t index, size_t len);
t_pile			new_pile();
int				*pile_get(t_pile *p, size_t i);
int				*pile_end(t_pile *p);
int				pile_offset(int i);

#endif
