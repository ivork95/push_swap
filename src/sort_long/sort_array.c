/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_array.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/05 17:17:24 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/12 17:03:51 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

#define CHUNK 6

int	*fill_array(t_stack *stack, int len)
{
	int	*arr;
	int	x;

	arr = malloc(sizeof(int) * len);
	x = 0;
	while (stack)
	{
		arr[x] = stack->num;
		stack = stack->next;
		x++;
	}
	return (arr);
}

int	*sort_array(int *arr, int len)
{
	int	*sorted_arr;
	int	biggest;
	int	i;
	int	j;

	sorted_arr = malloc(sizeof(int) * len);
	biggest = find_biggest(arr, len);
	i = 0;
	j = 0;
	while (1)
	{
		if (smallest_num(arr, arr[i], len))
		{
			sorted_arr[j] = arr[i];
			if (arr[i] == biggest)
				break ;
			arr[i] = biggest;
			i = 0;
			j++;
		}
		else
			i++;
	}
	return (sorted_arr);
}

int	*create_sorted_array(t_stack *stack_a, int len)
{
	int	*arr;

	arr = malloc(sizeof(int) * len);
	arr = fill_array(stack_a, len);
	return (sort_array(arr, len));
}

int	*remove_num(int *arr, int num)
{
	int	i;

	i = 0;
	while (arr[i] != num)
	{
		i++;
	}
	arr[i] = arr[0];
	arr++;
	return (arr);
}
