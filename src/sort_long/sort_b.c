/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_b.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/05 21:59:38 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/05 22:12:51 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int		find_next_smallest(t_stack *stack, int num)
{
	int index;
	int next;
	int i;

	next = -2147483648;
	index = 0;
	while(stack)
	{
		if (stack->num < num && stack->num > next)
		{
			next = stack->num;
			i = index;
		}
		stack = stack->next;
		index++;
	}
	return (i);
}

int		find_index_biggest(t_stack *stack)
{
	int count;
	int index;
	int num;

	count = 0;
	num = -2147483648;
	while(stack)
	{
		if (stack->num > num)
		{
			num = stack->num;
			index = count;
		}
		stack = stack->next;
		count++;
	}
	return (index);
}

void	sort_b(t_stack **stack, int num)
{
	int x;
	int len;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	if (is_biggest(*stack, num))
	{
		x = find_index_biggest(*stack);
	}
	if (is_smallest(*stack, num))
	{
		x = find_index_biggest(*stack);
	}
	else
	{
		x = find_next_smallest(*stack, num);
	}
	len = stack_len(*stack);

	if (x > len / 2)
	{
		x = len - x;
		while (x > 0)
		{
			reverse_rotate_stack(stack, "rrb\n");
			x--;
		}
	}
	else
	{
		while (x > 0)
		{
			rotate_stack(stack, "rb\n");
			x--;
		}
	}

}

void	biggest_to_top(t_stack **stack)
{
	int x;
	int len;

	len = stack_len(*stack);
	x = find_index_biggest(*stack);
		if (x > len / 2)
	{
		x = len - x;
		while (x > 0)
		{
			reverse_rotate_stack(stack, "rrb\n");
			x--;
		}
	}
	else
	{
		while (x > 0)
		{
			rotate_stack(stack, "rb\n");
			x--;
		}
	}
}