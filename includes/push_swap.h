/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/20 15:40:08 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/12 17:33:27 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;	
}					t_stack;

typedef struct t_tuple
{
	int				value;
	int				index;
}					t_tuple;

t_stack	*create_new_node(void);
t_stack	*stack_last(t_stack *stack);
int		*remove_num(int *arr, int num);
int		*create_sorted_array(t_stack *stack_a, int len);
int		*sort_array(int *arr, int len);
int		stack_len(t_stack *stack);
int		is_smallest(t_stack *stack, int smallest);
int		is_biggest(t_stack *stack, int biggest);
int		find_biggest(int *arr, int len);
int		smallest_num(int *arr, int value, int len);
int		find_index_biggest(t_stack *stack);
int		find_index_smallest(t_stack *stack);
int		find_next_smallest(t_stack *stack, int num);
int		get_index(t_stack **stack, int num);
int		is_ordered(t_stack *stack);
int		is_sorted(t_stack *stack);
void	stack_iter(t_stack *stack_a);
void	swap_stack(t_stack *stack, char *str);
void	push_stack(t_stack **stack1, t_stack **stack2, char *str);
void	rotate_stack(t_stack **stack, char *str);
void	reverse_rotate_stack(t_stack **stack, char *str);
void	sort_short(t_stack **stack_a, int len);
void	sort_long(t_stack **stack, int len);
void	sort_b(t_stack **stack, int num);
void	biggest_to_top(t_stack **stack);

#endif
