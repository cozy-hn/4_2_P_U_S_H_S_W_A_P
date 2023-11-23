#include "push_swap.h"

void arr_len(char **arr, int *arr_size)
{
    int i;

    i = 0;
    while (arr[i])
        i++;
    *arr_size = i;
}

int ft_atoi(const char *str)
{
    int i;
    int sign;
    long long result;

    i = 0;
    sign = 1;
    result = 0;
  if (str[i] == '-' || str[i] == '+')
  {
    if (str[i] == '-')
        sign = -1;
    i++;
  }
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            result = result * 10 + (str[i] - '0');
        else
            print_error();
        i++;
    }
    result *= sign;
    if (result > 2147483647 || result < -2147483648)
        print_error();
    return ((int)result);
}


int is_vaild(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if ((str[i] == '-' || str[i] == '+') && i == 0)
            i++;
        else if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
            print_error();
    }
    return (ft_atoi(str));
}

void is_dup(int num, t_stack *a)
{
    int i;
    t_list *head;

    i = 0;
    head = a->top;
    while (i < a->size)
    {
        if (head->num == num)
            print_error();
        head = head->next;
        i++;
    }
    a->size++;
}

int argv_parser(int argc, char **argv, t_stack *a)
{
    int i;
    int j;
    int tmp;
    int arr_size;
    char **arr;

    a->top = NULL;
    i= 0;
    while (++i < argc)
    {
        arr = ft_split(argv[i], ' ');
        arr_len(arr, &arr_size);
        if (arr_size == 0)
            print_error();
        j=-1;
        while(++j < arr_size)
        {
            tmp = is_vaild(arr[j]);
            is_dup(tmp, a);
            ft_lstadd_back(&a->top, ft_lstnew(tmp));
        }
        free(arr);
    }
}