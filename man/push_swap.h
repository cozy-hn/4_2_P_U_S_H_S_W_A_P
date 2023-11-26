/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:37:26 by jiko              #+#    #+#             */
/*   Updated: 2023/11/26 18:29:08 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_cost
{
    int	ra;
    int	rb;
    int	rr;
    int	rra;
    int	rrb;
    int	rrr;
    int cost;
}    t_cost;

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

void argv_parser(int argc, char **argv, t_stack *a);
void print_error();
t_list	*ft_lstlast(t_list *lst);
t_list *ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void    size_3(t_stack *s);
void    divide(t_stack *a, t_stack *b, int *pivot);
void    get_pivot(t_stack *s, int *pivot);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *str, int value, size_t size);
int     get_min_idx_arr(int *arr, int size);
int     min_max(int a, int b, int flag);
void    print_error();
void	greedy(t_stack *a, t_stack *b);
char	**ft_split(char const *str, char c);
size_t  ft_strlen(const char *s);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
int sx(char x, t_stack *s);
int ss(t_stack *a, t_stack *b);
int px(char x, t_stack *a, t_stack *b);
int rx(char x, t_stack *s);
int rr(t_stack *a, t_stack *b);
int rrx(char x, t_stack *s);
int rrr(t_stack *a, t_stack *b);
void case_0(t_cost *cost);
void case_1(t_cost *cost);
void case_2(t_cost *cost);
void case_3(t_cost *cost);
#endif