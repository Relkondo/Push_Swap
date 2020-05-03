/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 06:24:37 by scoron            #+#    #+#             */
/*   Updated: 2020/05/03 08:27:19 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile			new_pile()
{
    return (t_pile){NULL, 0, 0};
}

int				*pile_content(t_pile *p, size_t i)
{
    if (i >= p->size)
        return NULL;
    return (int*)(p->content + i * sizeof(int));
}

int				*pile_get(t_pile *p, int i)
{
    return (p)->content + pile_offset(i);
}

int				pile_offset(int i)
{
    return i * sizeof(int);
}

int				*pile_end(t_pile *p)
{
    return (p)->content + (p)->size * sizeof(int);
}

void				display_pile(t_pile *p, char *msg)
{
    size_t k = 0;
    ft_printf("%s - PILE : ", msg);
    while (k < p->size) {
        ft_printf("%d,", *pile_content(p, k));
        k++;
    }
    ft_printf(" OVER\n");
}
