#include "push_swap.h"

void pile_popback(t_pile *self, size_t len)
{
	self->size -= (len > self->size) ? self->size : len;
}

int pile_popindex(t_pile *self, size_t index, size_t len)
{
    const size_t	n = (len > self->size - index) ? self->size - index : len;

    if (index > self->size)
        return (1);
    ft_memmove(PILE_GET(self, index),
               PILE_GET(self, index + n),
               PILE_OFFSET(self, self->size - n - index));
    self->size -= n;
    return (0);
}
