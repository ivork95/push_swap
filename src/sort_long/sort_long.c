/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_long.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 15:11:00 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/05 22:31:24 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

#define CHUNK 6

int	*get_index(int *arr, int *index, t_stack *stack, int len)
{
	t_stack	*tmp;
	int		i;
	int		j;

	j = 0;
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

int	find_index_closest(int *index_arr, int len, int chunk_size)
{
	int	x;
	int	middle;
	int	closest;
	
	x = 0;
	middle = len / 2;
	closest = middle;
	if (len < chunk_size)
		chunk_size = len;
	while (x < chunk_size)
	{
		if (index_arr[x] <= middle)
		{
			if (index_arr[x] <= closest)
				closest = index_arr[x];
		}
		else
		{
			if (len - index_arr[x] <= closest)
				closest = index_arr[x];
		}
		x++;
	}
	return (closest);
}

void push_to_b(t_stack **stack_a, t_stack **stack_b, int x, int len)
{
	int count;

	count = x;
	if (count > len / 2)
		count = len - x;
	while (count > 0)
	{
		if(x > len / 2)
		{
			reverse_rotate_stack(stack_a, "rra\n");
		}
		else
			rotate_stack(stack_a, "ra\n");
		count--;
	}
	push_stack(stack_a, stack_b, "pa\n");
}

int		next_push(t_stack *stack, int index)
{
	while (index > 0)
	{
		stack = stack->next;
		index--;
	}
	return(stack->num);
}

void	sort_long(t_stack **stack_a, int len)
{
	t_stack	*stack_b;
	int		*arr;
	int		*index_arr;
	int		count;
	int		index;
	int		num;

	index_arr = malloc(sizeof(int) * len / CHUNK);
	count = len;
	stack_b = NULL;
	arr = create_sorted_array(*stack_a, len);
	while (count > 0)
	{
		index_arr = get_index(arr, index_arr, *stack_a, (len / CHUNK));
		index = find_index_closest(index_arr, stack_len(*stack_a), (len / CHUNK));
		num = next_push(*stack_a, index);
		sort_b(&stack_b, num);
		push_to_b(stack_a, &stack_b, index, stack_len(*stack_a));
		arr = remove_num(arr, stack_b->num);
		count--;
	}
	biggest_to_top(&stack_b);
	while (stack_b)
		push_stack(&stack_b, stack_a, "pa\n");
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
