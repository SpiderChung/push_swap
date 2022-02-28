/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greatest_sorting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:54:16 by schung            #+#    #+#             */
/*   Updated: 2022/02/28 19:38:24 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	check_position_list(t_stack **stack, t_stack *list)
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

t_stack	*check_min_list(t_stack **stack)
{
	t_stack	*min_list;
	t_stack	*tmp_list;

	min_list = *stack;
	tmp_list = *stack;
	while (tmp_list)
	{
		if (min_list->num > tmp_list->num)
			min_list = tmp_list;
		tmp_list = tmp_list->next;
	}
	return (min_list);
}

void	greatest_sorting(t_stack **stack_a, t_stack **stack_b, int count)
{
	check_position_list(stack_a, check_min_list(stack_b));
	printf("%d", count);
}