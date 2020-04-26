#include "push_swap.h"

int ps_get_size(t_pile *p, int limit)
{
    int		i;

    if (p->size == 0)
        return (0);
    i = 0;
    while (PILE_CONTENT(p, (int)p->size - 1 - i) <= limit &&
           PILE_CONTENT(p, (int)p->size - 1 - i) != 1)
        i++;
    return (i);
}

int ps_get_average(t_pile *p)
{
    int		i;
    float	sum;

    if (p->size == 0)
        return (0);
    i = p->size;
    sum = 0;
    while (--i >= 0)
        sum += PILE_CONTENT(p, i);
    return ((int)(sum / (int)p->size + 0.5));
}

int ps_get_average_section(t_pile *p, int top_value)
{
    int		i;
    float	sum;

    if (p->size == 0)
        return (0);
    i = 0;
    sum = 0;
    while (PILE_CONTENT(p, (int)p->size - 1 - i) <= top_value &&
           PILE_CONTENT(p, (int)p->size - 1 - i) != 1)
    {
        sum += PILE_CONTENT(p, (int)p->size - 1 - i);
        i++;
    }
    return ((int)(sum / i + 0.5));
}

int ps_get_max(t_pile *p)
{
	size_t	i;
	int		max;

	if (p->size == 0)
		return (0);
	i = -1;
	max = 0;
	while (++i < p->size)
	{
		if (max < PILE_CONTENT(p, i))
			max = PILE_CONTENT(p, i);
	}
	return (max);
}

int ps_get_min(t_pile *p)
{
    size_t	i;
    int		min;

    if (p->size == 0)
        return (0);
    min = PILE_CONTENT(p, 0);
    i = -1;
    while (++i < p->size)
    {
        if (min > PILE_CONTENT(p, i))
            min = PILE_CONTENT(p, i);
    }
    return (min);
}

