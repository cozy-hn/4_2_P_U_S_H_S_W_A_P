#include "push_swap.h"

void size_2(t_stack *s)
{
    if (s->top->num > s->top->next->num)
        sx('a', s);
}

void size_3(t_stack *s)
{
    int a;
    int b;
    int c;

    a = s->top->num;
    b = s->top->next->num;
    c = s->top->next->next->num;
    if (a>b && b>c)
    {
        sx('a', s);
        rrx('a', s);
    }
    else if (a>c && c>b)
        rx('a', s);
    else if (b>a && a>c)
        rrx('a', s);
    else if (b>c && c>a)
    {
        sx('a', s);
        rx('a', s);
    }
    else if (c>a && a>b)
        sx('a', s);
}

void size_x( t_stack *a, t_stack *b)
{
    
}

int main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;
    int size;

    stack_a.size = 0;
    stack_b.size = 0;
    if (argc == 1)
        exit(0);
    parse_argv(argc, argv, &stack_a);
    size = stack_a.size;
    if (size == 1)
        exit(0);
    if (size == 2)
        size_2(&stack_a);
    else if (size == 3)
        size_3(&stack_a);
    else
        size_x(&stack_a, &stack_b);
    exit(0);
}