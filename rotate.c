/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:01:21 by schung            #+#    #+#             */
/*   Updated: 2022/03/03 20:35:02 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

void	rotate(t_list **lst, int rev)
{
	t_list	*temp;

	if (rev)
	{
		temp = ft_lstake_last(lst);
		ft_lstadd_front(lst, temp);
	}
	else
	{
		temp = ft_lstake_first(lst);
		ft_lstadd_back(lst, temp);
	}
}

void	ra(t_list **lst, int w)
{
	rotate(lst, 0);
	if (w)
		ft_putstr_fd("ra\n", STDOUT);
}

void	rb(t_list **lst, int w)
{
	rotate(lst, 0);
	if (w)
		ft_putstr_fd("rb\n", STDOUT);
}

void	rra(t_list **lst, int w)
{
	rotate(lst, 1);
	if (w)
		ft_putstr_fd("rra\n", STDOUT);
}

void	rrb(t_list **lst, int w)
{
	rotate(lst, 1);
	if (w)
		ft_putstr_fd("rrb\n", STDOUT);
}
