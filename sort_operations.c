/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_operations.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/20 18:40:15 by ivork         #+#    #+#                 */
/*   Updated: 2021/05/20 21:57:08 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void	stack_swap(t_stack *stack)
{
	int tmp;


	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
}

void	stack_swap_both(t_stack *stack_a, t_stack *stack_b)
{
	stack_swap(stack_a);
	stack_swap(stack_b);
}

void 	stack_push(t_stack **stack1, t_stack **stack2)
{
	t_stack *tmp;

	stack_iter(*stack1);
	printf("---------\n");
	if (*stack2 == NULL)
	{
		*stack2 =  create_new_node();
	}
	tmp = *stack1;
	*stack1 = (*stack1)->next;
	tmp->next = *stack2;
	*stack2 = tmp;
	stack_iter(*stack1);
	printf("---------\n");
}