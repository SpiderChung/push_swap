/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func_lists.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:42:21 by schung            #+#    #+#             */
/*   Updated: 2022/02/23 16:40:11 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

t_stack	*ft_lstnew_ps(int content)
{
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (!temp)
		return (NULL);
	ft_bzero(temp, sizeof(t_stack));
	temp->num = content;
	return (temp);
}

t_stack	*ft_lstlast_ps(t_stack *lst)
{
	while (lst)
	{
		if (!(lst->next))
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_stack	*ft_lstfirst_ps(t_stack *lst)
{
	if (!lst)
		return (lst);
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

void	ft_lstadd_back_ps(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (lst)
	{
		if (*lst)
		{
			temp = ft_lstlast_ps(*lst);
			temp->next = new;
		}
		else
			*lst = new;
	}
}

int	ft_lstsize_ps(t_stack *lst)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = lst;
	if (temp)
	{
		while (temp)
		{
			i++;
			temp = temp->next;
		}
	}
	return (i);
}
