/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper3.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/12 17:21:55 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/13 21:09:51 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

int	find_next_smallest(t_stack *stack, int num)
{
	int	index;
	int	next;
	int	i;

	next = -2147483648;
	index = 0;
	while (stack)
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

int	find_index_biggest(t_stack *stack)
{
	int	count;
	int	index;
	int	num;

	count = 0;
	num = -2147483648;
	while (stack)
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

int	find_index_smallest(t_stack *stack)
{
	int	count;
	int	index;
	int	num;

	count = 0;
	num = 2147483647;
	while (stack)
	{
		if (stack->num < num)
		{
			num = stack->num;
			index = count;
		}
		stack = stack->next;
		count++;
	}
	return (index);
}

int	get_index(t_stack **stack, int num)
{
	if (is_biggest(*stack, num))
		return (find_index_biggest(*stack));
	if (is_smallest(*stack, num))
		return (find_index_biggest(*stack));
	else
		return (find_next_smallest(*stack, num));
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
