/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:02:12 by schung            #+#    #+#             */
/*   Updated: 2022/02/23 19:19:37 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

void	ra(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	*stack = temp->next;
	(*stack)->prev = 0;
	temp->next = 0;
	temp->prev = ft_lstlast_ps(*stack);
	ft_lstlast_ps(*stack)->next = temp;
	ft_putstr_fd("ra\n", STDOUT);
}

void	rb(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	*stack = temp->next;
	(*stack)->prev = 0;
	temp->next = 0;
	temp->prev = ft_lstlast_ps(*stack);
	ft_lstlast_ps(*stack)->next = temp;
	ft_putstr_fd("rb\n", STDOUT);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	temp = *stack_a;
	*stack_a = temp->next;
	(*stack_a)->prev = 0;
	temp->next = 0;
	temp->prev = ft_lstlast_ps(*stack_a);
	ft_lstlast_ps(*stack_a)->next = temp;
	temp = *stack_b;
	*stack_b = temp->next;
	(*stack_b)->prev = 0;
	temp->next = 0;
	temp->prev = ft_lstlast_ps(*stack_b);
	ft_lstlast_ps(*stack_b)->next = temp;
	ft_putstr_fd("rr\n", STDOUT);
}

void	rra(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*lst;

	lst = *stack;
	temp = ft_lstlast_ps(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	temp->next = lst;
	lst->prev = temp;
	temp->prev = 0;
	(*stack)->next = 0;
	*stack = temp;
	ft_putstr_fd("rra\n", STDOUT);
}

void	rrb(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*lst;

	lst = *stack;
	temp = ft_lstlast_ps(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	temp->next = lst;
	lst->prev = temp;
	temp->prev = 0;
	(*stack)->next = 0;
	*stack = temp;
	ft_putstr_fd("rra\n", STDOUT);
}
