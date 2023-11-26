/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:37:34 by jiko              #+#    #+#             */
/*   Updated: 2023/11/26 18:39:52 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_0(t_cost *cost)
{
	cost->rr = min_max(cost->rb, cost->ra, 0);
	cost->ra -= cost->rr;
	cost->rb -= cost->rr;
	cost->rra = 0;
	cost->rrb = 0;
	cost->rrr = 0;
	cost->cost = cost->rr + cost->ra + cost->rb;
}

void	case_1(t_cost *cost)
{
	cost->cost = cost->rb + cost->rra;
	cost->rr = 0;
	cost->rrb = 0;
	cost->rrr = 0;
	cost->ra = 0;
}

void	case_2(t_cost *cost)
{
	cost->cost = cost->rrb + cost->ra;
	cost->rr = 0;
	cost->rra = 0;
	cost->rrr = 0;
	cost->rb = 0;
}

void	case_3(t_cost *cost)
{
	cost->rrr = min_max(cost->rrb, cost->rra, 0);
	cost->rra -= cost->rrr;
	cost->rrb -= cost->rrr;
	cost->rr = 0;
	cost->ra = 0;
	cost->rb = 0;
	cost->cost = cost->rrr + cost->rra + cost->rrb;
}
