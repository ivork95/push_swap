/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_long.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 15:11:00 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/19 12:44:57 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdlib.h>

int	*get_index_arr(int *arr, int *index, t_stack *stack, int len)
{
	t_stack	*tmp;
	int		i;
	int		j;

	j = 0;
	if (stack_len(stack) < len)
		len = stack_len(stack);
	while (j < len)
	{
		i = 0;
		tmp = stack;
		while (tmp->num != arr[j] && stack_len(stack) > 1 && tmp != NULL)
		{
			tmp = tmp->next;
			if (tmp == NULL)
				break ;
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

void	push_to_b(t_stack **stack_a, t_stack **stack_b, int x, int len)
{
	int	count;

	count = x;
	if (count > len / 2)
		count = len - x;
	while (count > 0)
	{
		if (x > len / 2)
		{
			reverse_rotate_stack(stack_a, "rra\n");
		}
		else
			rotate_stack(stack_a, "ra\n");
		count--;
	}
	push_stack(stack_a, stack_b, "pb\n");
}

int	next_push(t_stack *stack, int index)
{
	while (index > 0)
	{
		stack = stack->next;
		index--;
	}
	return (stack->num);
}

void	sort_long(t_stack **stack_a, int len, int chunk)
{
	t_stack	*stack_b;
	int		*arr;
	int		*index_arr;
	int		index;
	int		num;

	index_arr = malloc(sizeof(int) * chunk);
	stack_b = NULL;
	arr = create_sorted_array(*stack_a, len);
	while (len > 0)
	{
		index_arr = get_index_arr(arr, index_arr, *stack_a, chunk);
		index = find_index_closest(index_arr, stack_len(*stack_a), chunk);
		num = next_push(*stack_a, index);
		sort_b(&stack_b, num);
		push_to_b(stack_a, &stack_b, index, stack_len(*stack_a));
		arr = remove_num(arr, stack_b->num, len);
		len--;
	}
	biggest_to_top(&stack_b);
	while (stack_b)
		push_stack(&stack_b, stack_a, "pa\n");
	free_stack(stack_b);
	free(index_arr);
	free(arr);
}
