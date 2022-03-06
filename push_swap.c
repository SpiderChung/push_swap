/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 22:18:18 by schung            #+#    #+#             */
/*   Updated: 2022/03/06 20:46:47 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

char	*ft_define(char **str)
{
	int		i;
	char	*dest;
	char	*temp;

	i = 0;
	dest = 0;
	while (str[i])
	{
		if (!dest)
		{
			dest = ft_strdup(str[i++]);
		}
		else
		{
			temp = dest;
			dest = ft_strjoin(dest, " ");
			free(temp);
			temp = dest;
			dest = ft_strjoin(dest, str[i++]);
			free(temp);
		}
	}
	return (dest);
}

int	ft_count_args(char *s, char c)
{
	int	i;
	int	quantity;

	i = 0;
	quantity = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			quantity++;
			i++;
	}
	return (quantity);
}

int	main(int argc, char **argv)
{
	char	*str;
	char	**start_array;
	int		quantity_args;
	int		*int_array;
	t_stack	*stack_a;

	if (argc > 1)
	{
		str = ft_define(argv + 1);
		start_array = ft_split(str, ' ');
		quantity_args = ft_count_args(str, ' ');
		check_input(start_array, quantity_args);
		int_array = ft_get_int(start_array, quantity_args);
		stack_a = creating_list(int_array, quantity_args);
		sorting_arr_int(int_array, quantity_args);
		leaks(start_array);
		free(str);
		sorting(&stack_a, quantity_args, int_array);
		free(int_array);
		ft_stack_free(stack_a);
	}
	return (0);
}
