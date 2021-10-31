/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/12 17:20:22 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/31 17:01:48 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

int	find_biggest(int *arr, int len)
{
	int	biggest;
	int	i;

	i = 0;
	biggest = arr[i];
	while (i < len)
	{
		if (arr[i] > biggest)
			biggest = arr[i];
		i++;
	}
	return (biggest);
}

int	smallest_num(int *arr, int value, int len)
{
	int	x;

	x = 0;
	while (x < len)
	{
		if (arr[x] < value)
		{
			value = arr[x];
			return (0);
		}
		x++;
	}
	return (1);
}

int	is_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (0);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_stack(t_stack *first)
{
	while (!(is_smallest(first, first->next->num)))
	{
		if (first->num > first->next->num)
			return (0);
		first = first->next;
	}
	return (1);
}

int	is_ordered(t_stack *stack)
{
	t_stack	*first;
	int		len;

	first = stack;
	len = stack_len(stack);
	while (!is_smallest(stack, stack->num))
		stack = stack->next;
	if (stack->next == NULL)
		return (check_stack(first));
	while (len - 1 > 0)
	{
		if (stack->next == NULL)
		{
			if (stack->num > first->num)
				return (0);
			stack = first;
			if (is_smallest(stack, stack->next->num))
				return (1);
		}
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
		len--;
	}
	return (1);
}
