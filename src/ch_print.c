#include "push_swap.h"

char		ch_code_ope(char *l) {
    char fl;
    fl = exist_in('a', l) != -1 ? 0 : 2;
    fl += exist_in('b', l) != -1 ? 0 : 1;
    fl += exist_in('s', l) != -1 ? 10 : 0;
    fl += exist_in('p', l) != -1 ? 20 : 0;
    fl += exist_in('r', l) != -1 ? 30 : 0;
    fl += ft_strlen(l) > 2 ? 10 : 0;

    return (fl);
}

int			ch_color_a(char ope, int pos, size_t si)
{
    int	check;

    check = 0;
    if ((ope && ope % 10 != 2 && ((pos == (int)(si - 1) && ope / 10 != 3) ||
            (pos == 0 && ope / 10 == 3) || (pos == (int)(si - 2) && ope / 10 == 1))))
        check = 1;
    return (check);
}

int			ch_color_b(char ope, int pos, size_t si)
{
    int	check;

    check = 0;
    if ((ope && ope % 10 != 1 && ((pos == (int)(si - 1) && ope / 10 != 3) ||
            (pos == 0 && ope / 10 == 3) || (pos == (int)(si - 2) && ope / 10 == 1))))
        check = 1;
    return (check);
}

void		ch_print_stacks(t_pile *a, t_pile *b, char ope)
{
    int		div;
    int     i;
    int     j;

    div = (int)a->size - (int)(b->size);
    i = a->size == 0 ? 0 : (int)(a->size - 1);
    j = b->size == 0 ? 0 : (int)(b->size - 1);
    while (i >= 0 && j >= 0)
    {
        if (div >= 0 && ft_printf(ch_color_a(ope, i, a->size) ?
                                  ft_strnjoin(3, FMT_BGREEN, "%6d ", FMT_OFF) : "%6d ", PILE_CONTENT(a, i)))
            i--;
        else
            ft_printf("%6c ", ' ');
        if (div <= 0 && ft_printf(ch_color_b(ope, j, b->size) ?
                                  ft_strnjoin(3, FMT_BGREEN, "%6d\n", FMT_OFF) : "%6d\n", PILE_CONTENT(b, j)))
            j--;
        else
            ft_printf("%6c\n", ' ');
        div -= div > 0 ? 1 : 0;
        div += div < 0 ? 1 : 0;
    }
    ft_printf(ft_strnjoin(3, FMT_BLUE, "%6c %6c\n%6c %6c\n\n", FMT_OFF), '_', '_', 'a', 'b');
}

