#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <stdlib.h>
# include <unistd.h>

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

int		sx(char x, t_stack *s);
int		ss(t_stack *a, t_stack *b);
int		px(char x, t_stack *a, t_stack *b);
int		rx(char x, t_stack *s);
int		rr(t_stack *a, t_stack *b);
int		rrx(char x, t_stack *s);
int		rrr(t_stack *a, t_stack *b);

#endif
