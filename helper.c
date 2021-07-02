/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/20 19:01:01 by ivork         #+#    #+#                 */
/*   Updated: 2021/06/11 21:28:59 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdlib.h>
#include <stdio.h>

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		exit (0);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	stack_iter(t_stack *stack_a)
{
	t_stack *current;

	current = stack_a;
	while (current)
	{
		printf("%d\n", current->num);
		current = current->next;
	}
}

int	stack_len(t_stack *stack)
{
	int i;

	i = 0;
	while(stack)
	{
		stack = stack->next;
		i++; 
	}
	return (i);
}

int	is_biggest(t_stack *stack)
{
	int biggest;

	biggest = stack->num ;
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

int	is_smallest(t_stack *stack)
{
	int smallest;

	smallest = stack->num ;
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

int find_biggest(int *arr, int len)
{
	int biggest;
	int i;

	i = 0;
	biggest = arr[i] ;
	while (i < len)
	{
		if (arr[i] > biggest)
			biggest = arr[i];
		i++;
	}
	return (biggest);	
}

int smallest_num(int *arr, int value, int len)
{
	int x;

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
