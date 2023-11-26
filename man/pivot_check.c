/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:13:19 by jiko              #+#    #+#             */
/*   Updated: 2023/11/26 18:45:10 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 1;
		while (j < size - i)
		{
			if (arr[j - 1] > arr[j])
			{
				tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	is_sorted(t_stack *s)
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

void	get_pivot(t_stack *s, int *pivot)
{
	int		i;
	int		*arr;
	t_list	*tmp;

	tmp = s->top;
	if (is_sorted(s))
		exit(0);
	arr = ft_calloc(s->size, sizeof(int));
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->num;
		tmp = tmp->next;
	}
	sort_arr(arr, s->size);
	pivot[0] = arr[s->size / 3];
	pivot[1] = arr[(s->size * 2) / 3];
	pivot[2] = arr[s->size - 1];
	free(arr);
}

void	divide(t_stack *a, t_stack *b, int *pivot)
{
	int	i;
	int	size;

	size = a->size;
	i = 1;
	while (i < (size * 2) / 3)
	{
		if (a->top->num < pivot[1])
		{
			px('b', b, a);
			if (b->top->num < pivot[0])
				rx('b', b);
			i++;
		}
		else
			rx('a', a);
	}
	while (a->size > 3)
	{
		if (a->top->num != pivot[2])
			px('b', b, a);
		else
			rx('a', a);
	}
	size_3(a);
}
