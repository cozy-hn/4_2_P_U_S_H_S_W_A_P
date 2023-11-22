#include "push_swap.h"

void print_error()
{
    write(2, "Error\n", 6);
    exit(1);
}

void	*ft_memset(void *str, int value, size_t size)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)str;
	while (size--)
		*tmp++ = value;
	return (str);
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