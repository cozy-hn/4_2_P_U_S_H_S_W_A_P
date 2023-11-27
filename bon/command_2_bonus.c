#include "push_swap_bonus.h"

int	rx(t_stack *s)
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
	return (1);
}

int	rr(t_stack *a, t_stack *b)
{
	rx(a);
	rx(b);
	return (1);
}

int	rrx(t_stack *s)
{
	t_list	*tmp;
	t_list	*last;

	if (s->size < 2)
		return (0);
	tmp = s->top;
	last = ft_lstlast(s->top);
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(&s->top, last);
	return (1);
}

int	rrr(t_stack *a, t_stack *b)
{
	rrx(a);
	rrx(b);
	return (1);
}

int	is_sorted(t_stack *s)
{
	t_list	*tmp;

	tmp = s->top;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}