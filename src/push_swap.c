/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/20 15:39:00 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/15 16:37:03 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		chunk;

	if (argc < 2)
		err_func();
	stack_a = fill_stack(argc, argv);
	if (stack_a == NULL)
		err_func();
	if (is_sorted(stack_a))
		return (0);
	chunk = 6;
	if (argc > 101)
		chunk = 20;
	if (argc <= 6)
		sort_short(&stack_a, (argc - 1));
	else
		sort_long(&stack_a, (argc - 1), chunk);
	free_stack(stack_a);
	return (0);
}
