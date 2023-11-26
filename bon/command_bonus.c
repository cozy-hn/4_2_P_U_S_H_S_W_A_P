#include "push_swap_bonus.h"

int	sx(t_stack *s)
{
	t_list	*tmp;

	if (s->size < 2)
		return (0);
	tmp = s->top;
	s->top = s->top->next;
	tmp->next = s->top->next;
	s->top->next = tmp;
	return (1);
}

int	ss(t_stack *a, t_stack *b)
{
	sx(a);
	sx(b);
	return (1);
}

int	px(t_stack *a, t_stack *b)
{
	t_list	*tmp;

	if (b->size == 0)
		return (0);
	tmp = b->top;
	b->top = b->top->next;
	ft_lstadd_front(&a->top, tmp);
	a->size++;
	b->size--;
	return (1);
}