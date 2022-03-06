/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:08:32 by schung            #+#    #+#             */
/*   Updated: 2022/03/03 20:38:57 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	is_digit(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
			return (0);
	}
	return (1);
}

void	check_repeat(char **str, int count_arg)
{
	int	i;
	int	k;

	i = 0;
	while (i < count_arg)
	{
		k = 1;
		while ((i + k) < count_arg)
		{
			if (ft_strncmp(str[i], str[i + k], 10))
				k++;
			else
				terminator();
		}
		i++;
	}
}

void	check_input(char **str, int count_arg)
{
	int	i;

	i = 1;
	while (i < count_arg)
	{
		if (is_digit(str[i]))
			i++;
		else
			terminator();
	}
	check_repeat(str, count_arg);
}

void	sorting_arr_int(int *arr, int count)
{
	int	tmp;
	int	i;
	int	k;

	i = -1;
	while (++i < count - 1)
	{
		k = 1;
		while ((i + k) < count)
		{
			if (arr[i] > arr[i + k])
			{
				tmp = arr[i];
				arr[i] = arr[i + k];
				arr[i + k] = tmp;
			}
			k++;
		}
	}
}

int	*ft_get_int(char **str, int count)
{
	int	*ret;
	int	i;

	ret = malloc(sizeof(int) * count + 1);
	if (!ret)
		return (0);
	i = 0;
	while (i < count)
	{
		ret[i] = ft_atoi_modern(str[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
