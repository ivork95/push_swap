/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_short.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/21 18:32:08 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/22 15:44:54 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <unistd.h>

t_stack	*sort_three(t_stack *stack)
{
	if (is_sorted(stack))
		return (stack);
	if (is_ordered(stack))
	{
		if (is_biggest(stack, stack->num))
			rotate_stack(&stack, "ra\n");
		else
			reverse_rotate_stack(&stack, "rra\n");
		return (stack);
	}
	if (is_smallest(stack, stack->num))
		reverse_rotate_stack(&stack, "rra\n");
	else if (is_biggest(stack, stack->num))
		rotate_stack(&stack, "ra\n");
	swap_stack(stack, "sa\n");
	return (stack);
}

static void	rotate_a(t_stack **stack, int num)
{
	int	x;
	int	len;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	len = stack_len(*stack);
	x = get_index(stack, num);
	if (x < len / 2)
	{
		while (x + 1 > 0)
		{
			rotate_stack(stack, "ra\n");
			x--;
		}
	}
	else
	{
		while ((len - x - 1) > 0)
		{
			reverse_rotate_stack(stack, "rra\n");
			len--;
		}
	}
}

static void	smallest_to_top(t_stack **stack)
{
	int	x;
	int	len;

	len = stack_len(*stack);
	x = find_index_smallest(*stack);
	if (x > len / 2)
	{
		x = len - x;
		while (x > 0)
		{
			reverse_rotate_stack(stack, "rra\n");
			x--;
		}
	}
	else
	{
		while (x > 0)
		{
			rotate_stack(stack, "ra\n");
			x--;
		}
	}
}

void	sort_short(t_stack **stack_a, int len)
{
	t_stack	*stack_b;

	stack_b = NULL;
	while (len > 3)
	{
		push_stack(stack_a, &stack_b, "pb\n");
		len--;
	}
	*stack_a = sort_three(*stack_a);
	while (stack_b)
	{
		rotate_a(stack_a, stack_b->num);
		push_stack(&stack_b, stack_a, "pa\n");
	}
	smallest_to_top(stack_a);
	free_stack(stack_b);
}
