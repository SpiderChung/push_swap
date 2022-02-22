/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_and_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 22:19:37 by schung            #+#    #+#             */
/*   Updated: 2022/02/22 22:25:52 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

void	ft_lst_free(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
}

void	terminator(void)
{
	ft_putstr_fd(ERR, STDERR);
	exit(1);
}

void	command_err(t_list *list_a, t_list *list_b)
{
	if (list_a)
		free_list(list_a);
	if (list_b)
		free_list(list_b);
	terminate();
}