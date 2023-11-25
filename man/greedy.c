/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:09:58 by jiko              #+#    #+#             */
/*   Updated: 2023/11/25 22:29:16 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int get_cost_a(t_stack *a, int num)
{
	int i;
	int last;
	int max;
	int max_idx;
	t_list *tmp;
	
	i = 0;
	max = -2147483648;
	tmp = a->top;
	last = ft_lstlast(a->top)->num;
	if (num > last && tmp->num > num)
		return (0);
	while (i + 1 < a->size)
	{
		if (tmp->num < num && tmp->next->num > num)
			return (i + 1);
		if (tmp->num >= max)
		{
			max = tmp->num;
			max_idx = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (max_idx);
}

	
static t_cost get_cost(t_stack *a, t_stack *b, int i, int num)
{
	int	best_cost;
	int arr[4];
	t_cost cost;
	
	cost.rb = i;
	cost.rrb = b->size - i;
	cost.ra = get_cost_a(a, num);
	cost.rra = a->size - cost.ra;
	arr[0] = min_max(cost.rb, cost.ra, 1);
	arr[1] = cost.rb + cost.rra;
	arr[2] = cost.rrb + cost.ra;
	arr[3] = min_max(cost.rrb, cost.rra, 1);
	best_cost = get_min_idx_arr(arr, 4);
	if (best_cost == 0)
		case_0(&cost);
	else if (best_cost == 1)
		case_1(&cost);
	else if (best_cost == 2)
		case_2(&cost);
	else if (best_cost == 3)
		case_3(&cost);
	return (cost);
}

static void command_operation(t_cost cost, t_stack *a, t_stack *b)
{
	while(cost.cost--)
	{
		if (cost.ra)
			cost.ra -= rx('a', a);
		else if (cost.rb)
			cost.rb -= rx('b', b);
		else if (cost.rr)
			cost.rr -= rr(a, b);
		else if (cost.rra)
			cost.rra -= rrx('a', a);
		else if (cost.rrb)
			cost.rrb -= rrx('b', b);
		else if (cost.rrr)
			cost.rrr -= rrr(a, b);
	}
	px('a', a, b);
}
	
void	greedy(t_stack *a, t_stack *b)
{
	int i;
	t_cost cost;
	t_cost min_cost;
	t_list *tmp;

	tmp = b->top;
	i = 0;
	min_cost.cost = 2147483647;
	while (i < b->size)
	{
		cost = get_cost(a, b, i, tmp->num);
		if (cost.cost < min_cost.cost)
			min_cost = cost;
		tmp = tmp->next;
		i++;
	}
	command_operation(min_cost, a, b);
}