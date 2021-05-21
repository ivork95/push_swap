/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_short.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/21 18:32:08 by ivork         #+#    #+#                 */
/*   Updated: 2021/05/21 18:51:36 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_stack *sort_three(t_stack *stack)
{
	
}

void	sort_short(t_stack **stack_a, int len)
{
	t_stack *stack_b;

	stack_b = create_new_node();
	if (len == 3)
		sort_three(stack_a);

}