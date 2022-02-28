/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:56:45 by schung            #+#    #+#             */
/*   Updated: 2022/02/28 19:35:33 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include <stdio.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define ERR "Error\n"

typedef struct s_stack
{
	int				num;
	int				index;
	int				flag;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_max
{
	int	index;
	int	len;
	int	current;
}   t_max;

typedef struct s_param
{
    int     max;
    int     min;
    int     mid;
    int     flag;
}   t_param;


/*________push_swap.c__________*/

/*________check_input.c__________*/
int     is_digit(char *str);
void    check_input(char **str, int count_arg);
int     *ft_get_int(char **str, int count);
void 	sorting_arr_int(int *arr, int count);


/*________add_func_lists.c__________*/
t_stack	*ft_lstnew_ps(int content);
t_stack	*ft_lstlast_ps(t_stack *lst);
t_stack	*ft_lstfirst_ps(t_stack *lst);
void	ft_lstadd_back_ps(t_stack **lst, t_stack *new);
int		ft_lstsize_ps(t_stack *lst);

/*________leaks_and_errors.c__________*/
void	ft_lst_free(t_stack *lst);
void	leaks(char **res);
void	terminator(void);
t_stack	*creating_list(int *arr, int n);

/*________utils.c__________*/
int		ft_atoi_modern(const char *str);
void	ft_sort(int *arr, int n);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	set_index(t_stack *stack, int *arr, int count);

/*________instructions_1.c__________*/
void	sa(t_stack	**stack);
void	sb(t_stack	**stack);
void	ss(t_stack	**stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_b, t_stack **stack_a);

/*________instructions_2.c__________*/
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);

/*________sorting.c__________*/
void	sorting(t_stack **stack_a, int count, int *arr_int);
void	ft_sort_for_3(t_stack **stack);
void	ft_sort_for_2(t_stack **stack);
void	ft_sort_for_5(t_stack **stack_a, t_stack **stack_b);

/*________greatest_sorting.c__________*/
void	greatest_sorting(t_stack **stack_a, t_stack **stack_b, int count);
t_stack	*check_min_list(t_stack **stack);
int	check_position_list(t_stack **stack, t_stack *list);


#endif