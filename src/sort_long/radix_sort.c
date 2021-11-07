/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/07 15:38:15 by ivork         #+#    #+#                 */
/*   Updated: 2021/11/07 15:38:15 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdlib.h>

void	get_indexed_stack(t_stack **stack_a, int *arr, int len)
{
	t_stack *tmp;
	int i;

	tmp = *stack_a;
	while (tmp)
	{
		i = 0;
		while (len > i)
		{
			if(tmp->num == arr[i])
			{
				tmp->num = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(arr);
}

int	get_biggest_bit(int biggest_num)
{
	int bits;

	bits = 0;
	while (biggest_num >> bits != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack **stack_a, int len)
{
	t_stack	*stack_b;
	int		*arr;
	int		i;
	int 	bits;

	arr = create_sorted_array(*stack_a, len);
	stack_b = NULL;
	get_indexed_stack(stack_a, arr, len);
	i = get_biggest_bit(len - 1);
	bits = 0;
	while (i > bits)
	{
		len = stack_len(*stack_a);
		while (len > 0)
		{
			if (((*stack_a)->num >> bits & 1) == 1)
				rotate_stack(stack_a, "ra\n");
			else
				push_stack(stack_a, &stack_b, "pb\n");
			len--;
		}
		while (stack_b)
			push_stack(&stack_b, stack_a, "pa\n");
		bits++;
	}
}
