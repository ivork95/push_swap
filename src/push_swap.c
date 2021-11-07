/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/20 15:39:00 by ivork         #+#    #+#                 */
/*   Updated: 2021/11/07 17:17:11 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
		return (0);
	stack_a = fill_stack(argc, argv);
	if (stack_a == NULL)
		err_func();
	if (is_sorted(stack_a))
		return (0);
	if (argc <= 6)
		sort_short(&stack_a, (argc - 1));
	else
		radix_sort(&stack_a, stack_len(stack_a));
	free_stack(stack_a);
	return (0);
}
