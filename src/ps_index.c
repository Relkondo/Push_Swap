#include "push_swap.h"

static int ps_sort_swapping(t_pile *p, int left, int right, int middle)
{
	int inter;

	while (left <= right)
	{
        while (PILE_CONTENT(p, right) < middle)
            right--;
		while (PILE_CONTENT(p, left) > middle)
			left++;
		if (right >= left)
		{
            inter = PILE_CONTENT(p, right);
            PILE_CONTENT(p, right) = PILE_CONTENT(p, left);
            PILE_CONTENT(p, left) = inter;
            right--;
			left++;
		}
	}
	return (left);
}

int ps_is_sorted(t_pile *p)
{
    int	i;

    if (p->size == 0)
        return (1);
    i = p->size;
    while (--i > 0)
    {
        if (PILE_CONTENT(p, i - 1) < PILE_CONTENT(p, i))
            return (0);
    }
    return (1);
}

void ps_sort(t_pile *p, int left, int right)
{
    int index;
	int middle;

	if (left < right) {
        middle = PILE_CONTENT(p, (right + left) / 2);
        index = ps_sort_swapping(p, left, right, middle);
        ps_sort(p, left, index - 1);
        ps_sort(p, index, right);
	}
}

void ps_index(t_pile *a, t_pile *b)
{
    int	i;
    int j;

    i = (int)a->size - 1;
    while (i >= 0)
    {
        j = 0;
        while (j < (int)b->size - 1)
        {
            if (PILE_CONTENT(a, i) == PILE_CONTENT(b, (int)b->size - 1 - j) &&
                PILE_CONTENT(b, (int)b->size - 1 - j) != 0x7FFFFFFF)
            {
                PILE_CONTENT(b, (int)b->size - 1 - j) = 0x7FFFFFFF;
                break ;
            }
            j++;
        }
        PILE_CONTENT(a, i) = j + 1;
        i--;
    }
    pile_clear(b);
    *b = NEW_PILE;
}


