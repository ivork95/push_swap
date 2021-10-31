/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/12 19:13:42 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/31 16:55:23 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h" 

static void	swap_or_push(t_stack **stack_a, t_stack **stack_b, char *operations)
{
	if (!ft_strncmp(operations, "sa", 3))
	{
		swap_stack(*stack_a, "\0");
	}
	else if (!ft_strncmp(operations, "sb", 3))
	{
		swap_stack(*stack_b, "\0");
	}
	else if (!ft_strncmp(operations, "ss", 3))
	{
		swap_stack(*stack_a, "\0");
		swap_stack(*stack_a, "\0");
	}
	else if (!ft_strncmp(operations, "pa", 3))
	{
		push_stack(stack_b, stack_a, "\0");
	}
	else if (!ft_strncmp(operations, "pb", 3))
	{
		push_stack(stack_a, stack_b, "\0");
	}
	else
		err_func();
}

static void	execute_operations(t_stack **stack_a, t_stack **stack_b,
							char *operations)
{
	if (operations[0] == 's' || operations[0] == 'p')
		swap_or_push(stack_a, stack_b, operations);
	else if (!ft_strncmp(operations, "ra", 3) && stack_a)
		rotate_stack(stack_a, "\0");
	else if (!ft_strncmp(operations, "rb", 3) && stack_b)
		rotate_stack(stack_b, "\0");
	else if (!ft_strncmp(operations, "rr", 3) && stack_a && stack_b)
	{
		rotate_stack(stack_a, "\0");
		rotate_stack(stack_b, "\0");
	}
	else if (!ft_strncmp(operations, "rra", 4) && stack_a)
		reverse_rotate_stack(stack_a, "\0");
	else if (!ft_strncmp(operations, "rrb", 4) && stack_a)
		reverse_rotate_stack(stack_b, "\0");
	else if (!ft_strncmp(operations, "rrr", 4) && stack_a && stack_b)
	{
		reverse_rotate_stack(stack_a, "\0");
		reverse_rotate_stack(stack_b, "\0");
	}
	else
		err_func();
}

static void	read_operations(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		if (ret < 0)
			err_func();
		if (ret > 0)
			execute_operations(stack_a, stack_b, line);
		free(line);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (0);
	stack_a = fill_stack(argc, argv);
	if (stack_a == NULL)
		err_func();
	read_operations(&stack_a, &stack_b);
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
