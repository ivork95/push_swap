/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_array.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/05 17:17:24 by ivork         #+#    #+#                 */
/*   Updated: 2021/11/07 17:32:06 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdlib.h>

void	fill_array(t_stack *stack, int *arr)
{
	int	x;

	x = 0;
	while (stack)
	{
		arr[x] = stack->num;
		stack = stack->next;
		x++;
	}
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
	free(arr);
	return (sorted_arr);
}

int	*create_sorted_array(t_stack *stack_a, int len)
{
	int	*arr;

	arr = malloc(sizeof(int) * len);
	fill_array(stack_a, arr);
	return (sort_array(arr, len));
}
