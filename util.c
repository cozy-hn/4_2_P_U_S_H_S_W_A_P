#include "push_swap.h"

void print_error()
{
    write(2, "Error\n", 6);
    exit(1);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*rtm;

	rtm = malloc(count * size);
	if (!rtm)
		print_error();
	ft_memset(rtm, 0, count * size);
	return (rtm);
}