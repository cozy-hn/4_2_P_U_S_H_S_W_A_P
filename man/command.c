/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:13:42 by jiko              #+#    #+#             */
/*   Updated: 2023/11/29 22:51:18 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sx(char x, t_stack *s)
{
	t_list	*tmp;

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

int	ss(t_stack *a, t_stack *b)
{
	sx('s', a);
	sx('s', b);
	ft_printf("ss\n");
	return (1);
}

int	px(char x, t_stack *a, t_stack *b)
{
	t_list	*tmp;

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

size_t	ft_strlen(const char *s)
{
	int	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize - 1 && *(src + i))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (ft_strlen(src));
}
