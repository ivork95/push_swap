/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/20 15:40:08 by ivork         #+#    #+#                 */
/*   Updated: 2021/05/25 16:25:14 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct		s_tree
{
	int				value;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

typedef struct		s_stack
{
	int				num;
	struct s_stack	*next;	
}					t_stack;

t_stack	*create_new_node(void);
t_stack	*stack_last(t_stack *stack);
int		stack_len(t_stack *stack);
int		is_smallest(t_stack *stack);
int		is_biggest(t_stack *stack);
void	stack_iter(t_stack *stack_a);
void	swap_stack(t_stack *stack, char *str);
void 	push_stack(t_stack **stack1, t_stack **stack2, char *str);
void	rotate_stack(t_stack **stack, char *str);
void	reverse_rotate_stack(t_stack **stack, char *str);
void	sort_short(t_stack **stack_a, int len);

#endif