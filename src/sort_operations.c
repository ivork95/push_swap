/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_operations.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/20 18:40:15 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/12 17:17:43 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	swap_stack(t_stack *stack, char *str)
{
	int	tmp;

	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
	write(1, str, ft_strlen(str));
}

void	push_stack(t_stack **stack1, t_stack **stack2, char *str)
{
	t_stack	*tmp;

	if (*stack2 == NULL)
	{
		*stack2 = create_new_node();
		if (*stack2 == NULL)
			exit (0);
		(*stack2)->num = (*stack1)->num;
		*stack1 = (*stack1)->next;
	}
	else
	{
		tmp = *stack1;
		*stack1 = (*stack1)->next;
		tmp->next = *stack2;
		*stack2 = tmp;
	}
	write(1, str, ft_strlen(str));
}

void	rotate_stack(t_stack **stack, char *str)
{
	t_stack	*tmp;

	if (!*stack)
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	stack_last(*stack)->next = tmp;
	write(1, str, ft_strlen(str));
}

void	reverse_rotate_stack(t_stack **stack, char *str)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = stack_last(*stack);
	tmp2 = *stack;
	while (tmp2->next->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
	write(1, str, ft_strlen(str));
}
