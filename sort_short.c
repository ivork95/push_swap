/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_short.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/21 18:32:08 by ivork         #+#    #+#                 */
/*   Updated: 2021/05/23 18:51:36 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <unistd.h>
#include <stdio.h>

t_stack	*sort_three(t_stack *stack)
{
	if (stack->num > stack->next->num && stack->num < stack->next->next->num)
		swap_stack(stack, "sa\n");
	else if (stack->num > stack->next->num && stack->next->num > stack->next->next->num)
	{
		swap_stack(stack, "sa\n");
		reverse_rotate_stack(&stack, "rra\n");
	}
	else if (stack->num > stack->next->num && stack->next->num < stack->next->next->num)
		rotate_stack(&stack, "ra\n");
	else if (stack->num < stack->next->num && stack->next->num > stack->next->next->num)
	{
		swap_stack(stack, "sa\n");
		rotate_stack(&stack, "ra\n");
	}
	else if (stack->num < stack->next->num && stack->next->num > stack->next->next->num)
	{
		swap_stack(stack, "sa\n");
		rotate_stack(&stack, "rra\n");
	}
	return (stack);
}

void	sort_short(t_stack **stack_a, int len)
{
	t_stack *stack_b;

	stack_b = NULL;
	while (len > 3)
	{
		push_stack(stack_a, &stack_b, "pb\n");
		len--;
	}
	*stack_a = sort_three(*stack_a);
	if (stack_b != NULL)
	{
		push_stack(&stack_b, stack_a, "pa\n");
		if (is_biggest(*stack_a))
			rotate_stack(stack_a, "ra\n");
		else if ((*stack_a)->num > (*stack_a)->next->num && 
				(*stack_a)->num > (*stack_a)->next->next->num)
		{
			reverse_rotate_stack(stack_a, "rra\n");
			swap_stack(*stack_a, "sa\n");
			rotate_stack(stack_a, "ra\n");
			rotate_stack(stack_a, "ra\n");
		}
		else if (!(is_smallest(*stack_a)))
			swap_stack(*stack_a, "sa\n");
	}
	if (stack_b != NULL)
	{
		push_stack(&stack_b, stack_a, "pa\n");
		if (is_biggest(*stack_a))
		{
			rotate_stack(stack_a, "ra\n");
		}
		else if ((*stack_a)->num > (*stack_a)->next->num && 
				(*stack_a)->num < (*stack_a)->next->next->num)
			swap_stack(*stack_a, "sa\n");
		else if ((*stack_a)->num > (*stack_a)->next->num && 
				(*stack_a)->num > (*stack_a)->next->next->num &&
				(*stack_a)->num < (*stack_a)->next->next->next->num)
		{	
			swap_stack(*stack_a, "sa\n");
			rotate_stack(stack_a, "ra\n");
			swap_stack(*stack_a, "sa\n");
			reverse_rotate_stack(stack_a, "rra\n");
		}
		else if ((*stack_a)->num > (*stack_a)->next->next->next->num &&
			(*stack_a)->num < stack_last(*stack_a)->num)
		{
			reverse_rotate_stack(stack_a, "rra\n");
			swap_stack(*stack_a, "sa\n");
			rotate_stack(stack_a, "ra\n");
			rotate_stack(stack_a, "ra\n");
		}
	}
}