/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:13:37 by jiko              #+#    #+#             */
/*   Updated: 2023/11/26 18:30:46 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void arr_len(char **arr, int *arr_size)
{
    int i;

    i = 0;
    while (arr[i])
        i++;
    *arr_size = i;
}

static int ft_atoi(const char *str)
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
        if (str[i] >= '0' && str[i] <= '9' && i < 13)
            result = result * 10 + (str[i] - '0');
        else
            print_error();
        i++;
    }
    result *= sign;
    if (result > 2147483647 || result < -2147483648LL)
        print_error();
    return ((int)result);
}


static int is_vaild(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if ((str[i] == '-' || str[i] == '+') && i == 0)
        {
            i++;
            if (!str[i])
                print_error();
        }
        else if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
            print_error();
    }
    return (ft_atoi(str));
}

static void is_dup(int num, t_stack *a)
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

void argv_parser(int argc, char **argv, t_stack *a)
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
            free(arr[j]);
        }
        free(arr);
    }
    
}