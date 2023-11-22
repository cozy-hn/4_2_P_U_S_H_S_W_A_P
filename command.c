#include "push_swap.h"

int sx(char x, t_stack *s)
{
    t_list *tmp;

    if (s->size < 2)
        return (0);
    tmp = s->top;
    s->top = s->top->next;
    tmp->next = s->top->next;
    s->top->next = tmp;
    if (x == 'a')
        ft_printf("sa\n");
    else if (x == 'b')
        ft_printf("sb\n");
    return (1);
}

int ss(t_stack *a, t_stack *b)
{
    sx('a', a);
    sx('b', b);
    ft_printf("ss\n");
    return (1);
}

int px(char x, t_stack *a, t_stack *b)
