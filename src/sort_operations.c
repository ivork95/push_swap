/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_operations.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/20 18:40:15 by ivork         #+#    #+#                 */
/*   Updated: 2021/11/07 17:12:00 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

void	swap_stack(t_stack *stack, const char *str)
{
	int	tmp;

	if (stack && stack->next)
	{
		tmp = stack->num;
		stack->num = stack->next->num;
		stack->next->num = tmp;
		write(1, str, ft_strlen(str));
	}
}

void	push_stack(t_stack **stack1, t_stack **stack2, const char *str)
{
	t_stack	*tmp;

	if (*stack1)
	{
		tmp = *stack1;
		*stack1 = (*stack1)->next;
		tmp->next = *stack2;
		*stack2 = tmp;
		write(1, str, ft_strlen(str));
	}
}

void	rotate_stack(t_stack **stack, const char *str)
{
	t_stack	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = NULL;
		stack_last(*stack)->next = tmp;
		write(1, str, ft_strlen(str));
	}
}

void	reverse_rotate_stack(t_stack **stack, const char *str)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*stack && (*stack)->next)
	{
		tmp = stack_last(*stack);
		tmp2 = *stack;
		while (tmp2->next->next != NULL)
			tmp2 = tmp2->next;
		tmp2->next = NULL;
		tmp->next = *stack;
		*stack = tmp;
		write(1, str, ft_strlen(str));
	}
}
