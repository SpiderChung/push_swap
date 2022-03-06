/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:48:47 by schung            #+#    #+#             */
/*   Updated: 2022/03/06 20:52:53 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

void	sorting(t_stack **stack_a, int count, int *arr_int)
{
	t_stack	*stack_b;

	stack_b = NULL;
	set_index(*stack_a, arr_int, count);
	if (check_sort(stack_a, count) == 1)
		exit(1);
	if (count == 2)
		ft_sort_for_2(stack_a);
	else if (count == 3)
		ft_sort_for_3(stack_a);
	else if (count > 3 && count <= 5)
		ft_sort_for_5(stack_a, &stack_b);
	else if (count > 5)
		big_stack_sort(stack_a, &stack_b, count);
	else
		return ;
}

void	throw_in_a(t_stack **stack_a, t_stack **stack_b, t_param *param)
{
	int	i;
	int	len;

	i = 0;
	len = ft_lstsize_ps(*stack_b);
	while (i < len)
	{
		if ((*stack_b)->index == param->min)
			check_min(stack_a, stack_b, param);
		else if ((*stack_b)->index >= param->mid)
		{
			(*stack_b)->flag = param->flag;
			pa(stack_b, stack_a);
		}
		else
			rb(stack_b);
		if (!(*stack_b))
			break ;
		i++;
	}
	inc_flag(param);
}

void	throw_in_b(t_stack **stack_a, t_stack **stack_b, t_param *param)
{
	int	flag_max;

	flag_max = (*stack_a)->flag;
	if ((*stack_a)->flag != 0)
	{
		while ((*stack_a)->flag == flag_max)
			in_b_dop(stack_a, stack_b, param);
		if (*stack_b)
			param->max = check_stack_max(stack_b)->index;
		param->mid = (param->max - param->min) / 2 + param->min;
	}
	else if ((*stack_a)->flag == 0)
	{
		while ((*stack_a)->flag != -1)
			in_b_dop(stack_a, stack_b, param);
		if (*stack_b)
			param->max = check_stack_max(stack_b)->index;
		param->mid = (param->max - param->min) / 2 + param->min;
	}
}
