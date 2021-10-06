/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_longb.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 15:11:00 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/05 21:23:49 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

#define CHUNK 6
int *get_index(int *arr, int *index, t_stack *stack, int len)
{
	t_stack *tmp;
	int i;
	int j;

	j = 0;
	stack_iter(stack);
	while (j < len)
	{
		i = 0;
		tmp = stack;
		while (tmp->num != arr[j] && stack_len(stack) > 1 && tmp != NULL)
		{
			tmp = tmp->next;
			if (tmp == NULL)
				break;
			i++;
		}
		index[j] = i;
		j++;
	}
	return (index);
}


int	find_closest(int *index, int len, int chunk_size)
{
	int x;
	int i;
	int cost;
	int middle;
	
	if (len == 1)
		return (index[0]);
	x = 0;
	middle = len / 2;
	cost = middle;
	while (x < (chunk_size))
	{
		if (index[x] <= middle)
		{
			if (cost > index[x])
			{
				cost = index[x];
				i = x;
			}
		}
		else if (index[x] > middle)
		{
			if (cost > abs(index[x] - len))
			{
				cost = abs(index[x] - len);
				i = x;
			}
		}
		x++;
	}
	return (index[i]);
}



int *remove_num(int *arr, int num)
{
	int  i;

	i = 0;
	while (arr[i] != num)
	{
		i++;
	}
	arr[i] = arr[0];
	arr++;
	return (arr);
}

void	sort_long(t_stack **stack_a, int len)
{
	int *arr;
	int *index;
	t_stack *current;
	t_stack *stack_b;
	int x;
	int count;

	index = malloc(sizeof(int) * len / CHUNK);
	current = *stack_a;
	x = 0;
	count = len;
	stack_b = NULL;
	arr = sort_array(arr, len);
	while (count > 0)
	{
		index = get_index(arr, index, *stack_a, (len / 6));
		x = find_closest(index, stack_len(*stack_a), len / CHUNK);
		push_to_b(stack_a, &stack_b, x, len);
		arr = remove_num(arr, stack_b->num);
		count--;
		printf("-------------------\n");
	}
	printf("stack_b\n");
	stack_iter(stack_b);
	printf("stack_a\n");
	stack_iter(*stack_a);
}






// int *sort_array(int *arr, int len)
// {
// 	t_stack *tmp;
// 	int biggest;
// 	int x;

// 	tmp = stack;
// 	biggest = find_biggest(stack);
// 	x = 0;
// 	while (tmp)
// 	{
// 		if (is_smallest(tmp))
// 		{
// 			arr[x] = tmp->num;
// 			if (tmp->num == biggest)
// 				break ;
// 			tmp->num = biggest;
// 			tmp = stack;
// 			x++;
// 		}
// 		else
// 			tmp = tmp->next;
// 	}
// 	return (arr);
// }
