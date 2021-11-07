/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/20 19:01:01 by ivork         #+#    #+#                 */
/*   Updated: 2021/11/07 17:37:15 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		exit (0);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	stack_len(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	is_biggest(t_stack *stack, int biggest)
{
	while (stack)
	{
		if (stack->num > biggest)
		{
			biggest = stack->num;
			return (0);
		}
		stack = stack->next;
	}
	return (1);
}

int	is_smallest(t_stack *stack, int smallest)
{
	while (stack)
	{
		if (stack->num < smallest)
		{
			smallest = stack->num;
			return (0);
		}
		stack = stack->next;
	}
	return (1);
}

