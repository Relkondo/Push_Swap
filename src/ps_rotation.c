#include "push_swap.h"

void ps_push_swap(t_pile *a, t_pile *b)
{
	int max;

	if (b->size == 0)
		return ;
	max = ps_get_max(b);
    ps_split_btoa(a, b, ps_get_average(b), b->size);
	while ((PILE_CONTENT(a, a->size - 1) == PILE_CONTENT(a, 0) + 1 ||
            PILE_CONTENT(a, a->size - 1) == 1) && !ps_is_sorted(a))
        ps_r(a, "ra\n");
    ps_push_swap(a, b);
	if (ps_get_size(a, max) >= 20)
        ps_roll_back_and_forth(a, b, max);
    ps_roll(a, b, max);
}

void ps_roll(t_pile *a, t_pile *b, int top_value)
{
    while (PILE_CONTENT(a, a->size - 1) <= top_value &&
           PILE_CONTENT(a, a->size - 1) != 1)
    {
        if (PILE_CONTENT(a, a->size - 1) == PILE_CONTENT(a, 0) + 1)
            ps_r(a, "ra\n");
        else
            ps_p(b, a, "pb\n");
    }
    if (ps_get_min(b) == PILE_CONTENT(a, 0) + 1)
        ps_push_swap(a, b);
}

void ps_roll_back_and_forth(t_pile *a, t_pile *b, int top_value)
{
    int average;
    int k;
    int i;

    average = ps_get_average_section(a, top_value);
    k = 0;
    while (PILE_CONTENT(a, a->size - 1) <= top_value &&
           PILE_CONTENT(a, a->size - 1) != 1)
    {
        if (PILE_CONTENT(a, a->size - 1) >= average)
        {
            ps_r(a, "ra\n");
            k++;
        }
        else
            ps_p(b, a, "pb\n");
    }
    i = -1;
    while (++i < k)
        if (PILE_CONTENT(b, b->size - 1) != ps_get_max(b))
            ps_rrr(a, b, "rrr\n");
        else
            ps_r_r(a, "rra\n");
    if (ps_get_min(b) == PILE_CONTENT(a, 0) + 1 && k > 0)
        ps_push_swap(a, b);
}
