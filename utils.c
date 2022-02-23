/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 22:31:12 by schung            #+#    #+#             */
/*   Updated: 2022/02/23 20:05:38 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

static int	ft_isspace(const char *src)
{
	int	i;

	i = 0;
	while ((src[i] == '\t') || (src[i] == '\n') || (src[i] == '\v')
		|| (src[i] == '\f') || src[i] == '\r' || src[i] == ' ')
	{
		i++;
	}
	return (i);
}

int	ft_atoi_modern(const char *str)
{
	int				i;
	int				k;
	unsigned long	n;

	k = 1;
	i = ft_isspace(str);
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			k = k * (-1);
		i++;
	}
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		if ((n > __INT_MAX__) && (k > 0))
			terminator();
		else if ((n > __INT_MAX__) && (str[i] - '0' > 8) && (k < 0))
			terminator();
		else
			i++;
	}
	return ((int)n * k);
}

/*int	*creat_arr(int argc, char **argv)
{
	int	*arr;
	int	flag;
	int	i;

	arr = (int *)malloc(sizeof(int) * (argc - 1));
	flag = 0;
	i = 1;
	while (i < argc)
	{
		arr[i - 1] = ft_atoi_mo(argv[i], &flag);
		if (flag)
		{
			free(arr);
			terminate();
		}
		i++;
	}
	return (arr);
}*/

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*lst;

	lst = *stack_a;
	temp = ft_lstlast_ps(*stack_a);
	while ((*stack_a)->next->next)
		*stack_a = (*stack_a)->next;
	temp->next = lst;
	lst->prev = temp;
	temp->prev = 0;
	(*stack_a)->next = 0;
	*stack_a = temp;
	lst = *stack_b;
	temp = ft_lstlast(*stack_b);
	while ((*stack_b)->next->next)
		*stack_a = (*stack_b)->next;
	temp->next = lst;
	lst->prev = temp;
	temp->prev = 0;
	(*stack_b)->next = 0;
	*stack_b = temp;
	ft_putstr_fd("rrr\n", STDOUT);
}

void	set_index(t_stack *stack, int *arr, int count)
{
	int		i;
	t_stack	*lst;

	lst = stack;
	while (lst)
	{
		i = 0;
		while (i < count)
		{
			if (arr[i] == lst->num)
				lst->index = i;
			i++;
		}
		lst = lst->next;
	}
}