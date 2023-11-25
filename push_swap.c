/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:13:24 by jiko              #+#    #+#             */
/*   Updated: 2023/11/25 17:12:35 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void size_x( t_stack *a, t_stack *b, int *pivot)
{
     get_pivot(a, pivot);
     divide(a, b, pivot);
     while (b->size > 0)
        greedy(a, b);
     
}

int main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;
    int size;
    int pivot[5];

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
        size_x(&stack_a, &stack_b, pivot);
    exit(0);
}