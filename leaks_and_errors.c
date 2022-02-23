/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_and_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 22:19:37 by schung            #+#    #+#             */
/*   Updated: 2022/02/23 19:45:42 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

void	ft_lst_free(t_stack *lst)
{
	t_stack	*temp;

	while (lst)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
}

void	leaks(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
}

void	terminator(void)
{
	ft_putstr_fd(ERR, STDERR);
	exit(1);
}

t_stack	*creating_list(int *arr, int n)
{
	t_stack	*stack_a;
	int		i;

	stack_a = NULL;
	i = 0;
	while (i < n)
	{
		ft_lstadd_back_ps(&stack_a, ft_lstnew_ps(arr[i]));
		printf("arr[i] = %d \n", arr[i]);
		i++;
	}
	return (stack_a);
}
