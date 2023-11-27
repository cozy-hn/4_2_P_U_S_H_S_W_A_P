#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include "./gnl/get_next_line_bonus.h"

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

void	argv_parser(int argc, char **argv, t_stack *a);
char	**ft_split(char const *str, char c);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	print_error(void);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int	sx(t_stack *s);
int	ss(t_stack *a, t_stack *b);
int	px(t_stack *a, t_stack *b);
int	rx(t_stack *s);
int	rr(t_stack *a, t_stack *b);
int	rrx(t_stack *s);
int	rrr(t_stack *a, t_stack *b);
int	is_sorted(t_stack *s);

#endif
