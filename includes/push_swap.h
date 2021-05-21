/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/20 15:40:08 by ivork         #+#    #+#                 */
/*   Updated: 2021/05/21 17:20:19 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct		s_stack
{
	int				num;
	struct s_stack	*next;	
}					t_stack;

t_stack	*create_new_node(void);
t_stack	*stack_last(t_stack *stack);
int		stack_len(t_stack *stack);
void	stack_iter(t_stack *stack_a);
void	stack_swap(t_stack *stack);
void	stack_swap_both(t_stack *stack_a, t_stack *stack_b);
void 	stack_push(t_stack **stack1, t_stack **stack2);
void	rotate_stack(t_stack **stack);
void	reverse_rotate_stack(t_stack **stack);
#endif