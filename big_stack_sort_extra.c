/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_sort_extra.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:38:03 by schung            #+#    #+#             */
/*   Updated: 2022/03/06 21:23:26 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

void	check_min_b(t_stack **stack_a, t_stack **stack_b, t_param *param)
{
	if ((*stack_a)->index == param->min)
	{
		ra(stack_a);
		param->min++;
		check_min(stack_a, stack_b, param);
	}
	else if (ft_lstsize_ps(*stack_b) > 0 && (*stack_b)->index == param->min)
	{
		(*stack_b)->flag = -1;
		pa(stack_b, stack_a);
		ra(stack_a);
		param->min++;
		check_min(stack_a, stack_b, param);
	}
	else if ((*stack_a)->next->index == param->min && ft_lstsize_ps
		(*stack_b) > 1 && (*stack_b)->next->index == param->min + 1)
	{
		ss(stack_a, stack_b);
		(*stack_a)->flag = -1;
		ra(stack_a);
		param->min++;
		check_min(stack_a, stack_b, param);
	}
}

void	check_min(t_stack **stack_a, t_stack **stack_b, t_param *param)
{
	if ((*stack_a)->index == param->min)
		check_min_b(stack_a, stack_b, param);
	else if (ft_lstsize_ps(*stack_b) > 0 && (*stack_b)->index == param->min)
		check_min_b(stack_a, stack_b, param);
	else if ((*stack_a)->next->index == param->min && ft_lstsize_ps
		(*stack_b) > 1 && (*stack_b)->next->index == param->min + 1)
		check_min_b(stack_a, stack_b, param);
	else if ((*stack_a)->next->index == param->min)
	{
		sa(stack_a);
		(*stack_a)->flag = -1;
		ra(stack_a);
		param->min++;
		check_min(stack_a, stack_b, param);
	}
	else if (ft_lstsize_ps(*stack_b) > 2 && ft_lstlast_ps
		(*stack_b)->index == param->min)
	{
		rrb(stack_b);
		pa(stack_b, stack_a);
		(*stack_a)->flag = -1;
		ra(stack_a);
		param->min++;
		check_min(stack_a, stack_b, param);
	}
}

void	in_b_dop(t_stack **stack_a, t_stack **stack_b, t_param *param)
{
	if ((*stack_a)->index == param->min)
	{
		(*stack_a)->flag = -1;
		ra(stack_a);
		param->min++;
		check_min(stack_a, stack_b, param);
	}
	else
	{
		pb(stack_a, stack_b);
		check_min(stack_a, stack_b, param);
	}
}

void	inc_flag(t_param *param)
{
	param->max = param->mid;
	param->mid = (param->max - param->min) / 2 + param->min;
	param->flag++;
}

void	first_throw_in_b(t_stack **stack_a, t_stack **stack_b, t_param *param)
{
	int	i;
	int	len;

	i = 0;
	len = ft_lstsize_ps(*stack_a);
	while (i < len)
	{
		if ((*stack_a)->index <= param->mid)
		{
			pb(stack_a, stack_b);
		}
		else
		{
			if (ft_lstsize_ps(*stack_b) > 1
				&& (*stack_b)->index < (param->mid / 2))
				rr(stack_a, stack_b);
			else
				ra(stack_a);
		}
		i++;
	}
	inc_flag(param);
}
