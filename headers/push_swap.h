/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:56:45 by schung            #+#    #+#             */
/*   Updated: 2022/02/22 22:28:47 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define ERR "Error\n"

typedef struct s_stack
{
	int             index;
	int             flag;
    struct s_stack  *next;
    struct s_stack  *prev;
}	t_stack;

typedef struct s_param
{
    int     max;
    int     min;
    int     middle;
    int     flag;
}   t_param;


/*________push_swap.c__________*/

/*________push_swap_utils.c__________*/

/*________leaks_and_errors.c__________*/
void	ft_lst_free(t_list *lst);
void	terminator(void);
void	command_err(t_list *list_a, t_list *list_b);

/*________utils.c__________*/
int     ft_atoi_modern(const char *str);
void    ft_sort(int *arr, int n);

/*________rotate.c__________*/
void	rotate(t_list **lst, int rev);
void	ra(t_list **lst, int w);
void	rb(t_list **lst, int w);
void	rra(t_list **lst, int w);
void	rrb(t_list **lst, int w);

#endif