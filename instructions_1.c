/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:01:59 by schung            #+#    #+#             */
/*   Updated: 2022/02/23 19:29:58 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

void	sa(t_stack	**stack)
{
	t_stack	*temp;

	temp = (*stack)->next->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next->next = (*stack);
	*stack = (*stack)->next;
	(*stack)->prev = 0;
	(*stack)->next->next = temp;
	ft_putstr_fd("sa\n", STDOUT);
}

void	sb(t_stack	**stack)
{
	t_stack	*temp;

	temp = (*stack)->next->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next->next = (*stack);
	*stack = (*stack)->next;
	(*stack)->prev = 0;
	(*stack)->next->next = temp;
	ft_putstr_fd("sb\n", STDOUT);
}

void	ss(t_stack	**stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	temp = (*stack_a)->next->next;
	(*stack_a)->prev = (*stack_a)->next;
	(*stack_a)->next->next = (*stack_a);
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = 0;
	(*stack_a)->next->next = temp;
	temp = (*stack_b)->next->next;
	(*stack_b)->prev = (*stack_b)->next;
	(*stack_b)->next->next = (*stack_b);
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = 0;
	(*stack_b)->next->next = temp;
	ft_putstr_fd("ss\n", STDOUT);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	if (!*stack_b)
	{
		temp_a = (*stack_a)->next;
		*stack_b = *stack_a;
		*stack_a = temp_a;
		(*stack_a)->prev = 0;
		(*stack_b)->next = 0;
	}
	else
	{
		temp_b = (*stack_b);
		temp_a = (*stack_a)->next;
		*stack_b = *stack_a;
		(*stack_b)->next = temp_b;
		temp_b->prev = (*stack_b);
		*stack_a = temp_a;
		(*stack_a)->prev = 0;
	}
	ft_putstr_fd("pb\n", STDOUT);
}

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*temp_b;
	t_stack	*temp_a;

	if (!(*stack_b)->next)
	{
		temp_a = (*stack_a);
		temp_b = (*stack_b)->next;
		*stack_a = *stack_b;
		(*stack_a)->next = temp_a;
		temp_a->prev = (*stack_a);
		*stack_b = temp_b;
	}
	else
	{
		temp_a = (*stack_a);
		temp_b = (*stack_b)->next;
		*stack_a = *stack_b;
		(*stack_a)->next = temp_a;
		temp_a->prev = (*stack_a);
		*stack_b = temp_b;
		(*stack_b)->prev = 0;
	}
	ft_putstr_fd("pa\n", STDOUT);
}
