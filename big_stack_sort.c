/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:54:16 by schung            #+#    #+#             */
/*   Updated: 2022/03/03 20:38:37 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	check_sort(t_stack **stack, int count)
{
	t_stack	*temp_stack;

	temp_stack = *stack;
	if (ft_lstsize_ps(*stack) != count)
		return (0);
	while (temp_stack->next)
	{
		if (temp_stack->index > temp_stack->next->index)
			return (0);
		temp_stack = temp_stack->next;
	}
	return (1);
}

int	check_position(t_stack **stack, t_stack *list)
{
	t_stack	*temp_list;
	int		i;

	i = 0;
	temp_list = *stack;
	while (temp_list != list)
	{
		temp_list = temp_list->next;
		i++;
	}
	return (i);
}

t_stack	*check_stack_min(t_stack **stack)
{
	t_stack	*min_list;
	t_stack	*temp_list;

	min_list = *stack;
	temp_list = *stack;
	while (temp_list)
	{
		if (min_list->num > temp_list->num)
			min_list = temp_list;
		temp_list = temp_list->next;
	}
	return (min_list);
}

t_stack	*check_stack_max(t_stack **stack)
{
	t_stack	*max_list;
	t_stack	*temp_list;

	max_list = *stack;
	temp_list = *stack;
	while (temp_list)
	{
		if (max_list->num < temp_list->num)
			max_list = temp_list;
		temp_list = temp_list->next;
	}
	return (max_list);
}

void	big_stack_sort(t_stack **stack_a, t_stack **stack_b, int count)
{
	t_param	param;

	ft_bzero(&param, sizeof(t_param));
	set_stack_param(&param, stack_a);
	while (check_sort(stack_a, count) != 1)
	{
		if (!*stack_b && param.flag == 0)
			first_throw_in_b(stack_a, stack_b, &param);
		else if (!*stack_b)
			throw_in_b(stack_a, stack_b, &param);
		else
			throw_in_a(stack_a, stack_b, &param);
	}
}
