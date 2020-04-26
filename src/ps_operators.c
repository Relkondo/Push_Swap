#include "push_swap.h"

void ps_r(t_pile *p, char *to_print)
{

    int inter;

    if (p->size == 0)
        return ;
    inter = PILE_CONTENT(p, p->size - 1);
    pile_popback(p, 1);
    pile_insert(p, &inter, 1, 0);
    if (*to_print)
        ft_printf("%s", to_print);
}

void ps_r_r(t_pile *p, char *to_print)
{
    int inter;

    if (p->size == 0)
        return ;
    inter = PILE_CONTENT(p, 0);
    pile_addall(p, &inter, 1);
    pile_popindex(p, 0, 1);
    if (*to_print)
        ft_printf("%s", to_print);
}

void ps_p(t_pile *receiver, t_pile *sender, char *to_print)
{
    int inter;

    if (sender->size == 0)
        return ;
    inter = PILE_CONTENT(sender, sender->size - 1);
    pile_popback(sender, 1);
    pile_addall(receiver, &inter, 1);
    if (*to_print)
        ft_printf("%s", to_print);
}

void ps_s(t_pile *p, char *to_print)
{
    int inter;

    if (p->size < 2)
        return ;
    inter = PILE_CONTENT(p, p->size - 2);
    PILE_CONTENT(p, p->size - 2) = PILE_CONTENT(p, p->size - 1);
    PILE_CONTENT(p, p->size - 1) = inter;
    if (*to_print)
        ft_printf("%s", to_print);
}