#include "push_swap_bonus.h"

static int is_valid_cmd(t_stack *a, t_stack *b, int len, char *cmd)
{
	if (len == 3 && cmd[0] == 's' && cmd[1] == 'a' )
		return(sx(a));
	else if (len == 3 && cmd[0] == 's' && cmd[1] == 'b' )
		return(sx(b));
	else if (len == 3 && cmd[0] == 's' && cmd[1] == 's' )
		return(ss(a, b));
	else if (len == 3 && cmd[0] == 'p' && cmd[1] == 'a' )
		return(px(a, b));
	else if (len == 3 && cmd[0] == 'p' && cmd[1] == 'b' )
		return(px(b, a));
	else if (len == 3 && cmd[0] == 'r' && cmd[1] == 'a' )
		return(rx(a));
	else if (len == 3 && cmd[0] == 'r' && cmd[1] == 'b' )
		return(rx(b));
	else if (len == 3 && cmd[0] == 'r' && cmd[1] == 'r' )
		return(rr(a, b));
	else if (len == 4 && cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == 'a')
		return(rrx(a));
	else if (len == 4 && cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == 'b')
		return(rrx(b));
	else if (len == 4 && cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == 'r')
		return(rrr(a, b));
	return (-1);
}

static void excute(t_stack *a, t_stack *b, char *cmd)
{
	int	flag;

	flag = is_valid_cmd(a, b, ft_strlen(cmd), cmd);
	if (flag == -1)
		print_error();
	free(cmd);
	cmd = get_next_line(0);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char    *cmd;

	stack_a.size = 0;
	stack_b.size = 0;
	if (argc == 1)
		exit(0);
	argv_parser(argc, argv, &stack_a);
	cmd = get_next_line(0);
	while (cmd)
		excute(&stack_a, &stack_b, cmd);
	if (is_sorted(&stack_a) && stack_b.size == 0)
	{
		if(write(1, "OK\n", 3) != 3)
			print_error();
	}
	else
		if(write(1, "KO\n", 3) != 3)
			print_error();
	exit(0);
}
