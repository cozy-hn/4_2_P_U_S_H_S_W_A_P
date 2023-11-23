/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42seoul.k>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:37:26 by jiko              #+#    #+#             */
/*   Updated: 2023/08/15 19:37:27 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
// # include <unistd.h>
// # include "./ft_printf/ft_printf.h"

typedef struct s_cost
{
    int	ra;
    int	rb;
    int	rr;
    int	rra;
    int	rrb;
    int	rrr;
}	t_cost;

typedef struct s_list
{
	int				num;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	int				size;
	struct s_list	*top;
}	t_stack;

void print_error();
t_list	*ft_lstlast(t_list *lst);

#endif