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
{
    t_list *tmp;

    if (b->size == 0)
        return (0);
    tmp = b->top;
    b->top = b->top->next;
    ft_lstadd_front(&a->top, tmp);
    a->size++;
    b->size--;
    if (x == 'a')
        ft_printf("pa\n");
    else if (x == 'b')
        ft_printf("pb\n");
    return (1);
}

int rx(char x, t_stack *s)
{
    t_list *tmp;

    if (s->size < 2)
        return (0);
    tmp = s->top;
    s->top = s->top->next;
    ft_lstadd_back(&s->top, tmp);
    ft_lstlast(s->top)->next = NULL;
    if (x == 'a')
        ft_printf("ra\n");
    else if (x == 'b')
        ft_printf("rb\n");
    return (1);
}

int rr(t_stack *a, t_stack *b)
{
    rx('a', a);
    rx('b', b);
    ft_printf("rr\n");
    return (1);
}

int rrx(char x, t_stack *s)
{
    t_list *tmp;
    t_list *last;

    if (s->size < 2)
        return (0);
    tmp = s->top;
    last = ft_lstlast(s->top);
    while (tmp->next != last)
        tmp = tmp->next;
    tmp->next = NULL;
    ft_lstadd_front(&s->top, last);
    if (x == 'a')
        ft_printf("rra\n");
    else if (x == 'b')
        ft_printf("rrb\n");
    return (1);
}

int rrr(t_stack *a, t_stack *b)
{
    rrx('a', a);
    rrx('b', b);
    ft_printf("rrr\n");
    return (1);
}