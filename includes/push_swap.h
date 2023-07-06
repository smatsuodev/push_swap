/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:53:57 by smatsuo           #+#    #+#             */
/*   Updated: 2023/07/06 12:04:06 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"

// Error handling
void		exit_on_error(void);

// Opearations
typedef enum e_op {
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_op;

// Operation List
typedef struct s_op_list	t_op_list;
struct s_op_list {
	t_op		op;
	t_op_list	*next;
};

// Controls of t_op_list
t_op_list	*new_op_list(t_op op);
t_op_list	*append_op(t_op_list *list, t_op op);
void		print_op(t_op op);
void		print_ops(t_op_list *list);
void		destory_op_list(t_op_list *list);

// Stack
typedef struct s_stack {
	int			*buffer_a;
	int			*buffer_b;
	int			front_a;
	int			rear_a;
	int			front_b;
	int			rear_b;
	int			size;
	t_op_list	*op_list;
}	t_stack;

// Constructors/Destructor of stack
t_stack		*new_empty_stack(int size);
t_stack		*new_stack_from(char **str_arr, int arr_len);
void		set_string_to_stack(t_stack *stack, char **str_arr);
void		destory_stack(t_stack *stack);

// Controls of stack
int			at_a(t_stack *stack, int index);
int			at_b(t_stack *stack, int index);
void		push_to_a(t_stack *stack, int value);
void		push_to_b(t_stack *stack, int value);
int			pop_from_a(t_stack *stack);
int			pop_from_b(t_stack *stack);
void		rotate_a(t_stack *stack);
void		rotate_b(t_stack *stack);
void		rev_rotate_a(t_stack *stack);
void		rev_rotate_b(t_stack *stack);
void		record_op_to_stack(t_stack *stack, t_op op);
void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *stack);
void		pa(t_stack *stack);
void		pb(t_stack *stack);
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *stack);
void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *stack);

// Push Swap
void		solve_in_3(t_stack *stack);

// String Array
char		**flatten_str_arr(char **str_arr, int arr_len);
int			count_strings(char **str_arr, int arr_len);
void		free_str_arr(char **arr);

// Validation
int			is_valid_nums(char **arr);
int			is_nums_unique(int *arr, int arr_len);

// Utils
int			ft_atoi_ex(char *s, int *iserr);

#endif
