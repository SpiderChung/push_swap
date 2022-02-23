/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:48:47 by schung            #+#    #+#             */
/*   Updated: 2022/02/23 20:19:46 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

void	ft_sort_for_2(t_stack **stack)
{
	if ((*stack)->num > (*stack)->next->num)
		sa(stack);
}

void	ft_sort_for_3(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->num;
	b = (*stack)->next->num;
	c = (*stack)->next->next->num;
	if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a < b && b > c && c > a)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && c < a)
		rra(stack);
	else if (a > b && b < c && c > a)
		sa(stack);
	else if (a > b && b < c && c < a)
		ra(stack);
}

void	ft_sort_for_5(t_stack **stack_a, t_stack **stack_b)
{
	min_in_b(stack_a, stack_b);
	ft_sorting_3(stack_a);
	while (check_len_list(stack_b) > 0)
		pa(stack_b, stack_a);
}

void	sorting(t_stack **stack_a, int count, int *arr_int)
{
	t_stack	*stack_b;

	stack_b = NULL;
	set_index(*stack_a, arr_int, count);
	if (count == 2)
		ft_sorting_2(stack_a);
	else if (count == 3)
		ft_sorting_3(stack_a);
	else if (count > 3 && count < 6)
		ft_sorting_5(stack_a, &stack_b);
	else if (count > 5)
		greatest_sorting(stack_a, &stack_b, count);
	else
		return ;
}