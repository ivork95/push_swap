/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_b.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/05 21:59:38 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/19 12:50:55 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdlib.h>

void	sort_b(t_stack **stack, int num)
{
	int	x;
	int	len;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	x = get_index(stack, num);
	len = stack_len(*stack);
	if (x > len / 2)
	{
		x = len - x;
		while (x > 0)
		{
			reverse_rotate_stack(stack, "rrb\n");
			x--;
		}
	}
	else
	{
		while (x > 0)
		{
			rotate_stack(stack, "rb\n");
			x--;
		}
	}
}

void	biggest_to_top(t_stack **stack)
{
	int	x;
	int	len;

	len = stack_len(*stack);
	x = find_index_biggest(*stack);
	if (x > len / 2)
	{
		x = len - x;
		while (x > 0)
		{
			reverse_rotate_stack(stack, "rrb\n");
			x--;
		}
	}
	else
	{
		while (x > 0)
		{
			rotate_stack(stack, "rb\n");
			x--;
		}
	}
}
