/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:19:02 by jiko              #+#    #+#             */
/*   Updated: 2023/11/25 23:55:24 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int rx(char x, t_stack *s)
{
    t_list	*tmp;
	int		i;

    if (s->size < 2)
        return (0);
    tmp = s->top;
    s->top = s->top->next;
    ft_lstadd_back(&s->top, tmp);
	i = 0;
	tmp = s->top;
	while (i++ < s->size - 1)
		tmp = tmp->next;
	tmp->next = NULL;
    if (x == 'a')
        ft_printf("ra\n");
    else if (x == 'b')
        ft_printf("rb\n");
    return (1);
}

int rr(t_stack *a, t_stack *b)
{
    rx('r', a);
    rx('r', b);
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
    rrx('r', a);
    rrx('r', b);
    ft_printf("rrr\n");
    return (1);
}
