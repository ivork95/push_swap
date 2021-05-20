/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/20 15:39:00 by ivork         #+#    #+#                 */
/*   Updated: 2021/05/20 21:52:25 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

int check_argument(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' && str[i + 1] != '\0')
		i++;
	while (*str == '0')
		str++;
	while(str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i > 9 && ft_atoi(str) == 0)
		return (0);
	return (1);
}

void	stack_iter(t_stack *stack_a)
{
	t_stack *current;

	current = stack_a;
	while (current)
	{
		printf("%d\n", current->num);
		current = current->next;
	}
}


t_stack	*create_new_node(void)
{
	t_stack	*first;

	first = (t_stack*)malloc(sizeof(t_stack));
	first->next = NULL;
	return (first);
}

t_stack *fill_stack(int argc, char **argv, t_stack *stack_a)
{
	t_stack *tmp;
	int i;

	i = 1;
	stack_a = create_new_node();
	if (stack_a == NULL)
		return (NULL);
	tmp = stack_a;
	while (i < argc)
	{
		if (!check_argument(argv[i]))
			return (NULL);
		tmp->num = ft_atoi(argv[i]);
		tmp->next = NULL;
		if  (i < argc - 1)
		{
			tmp->next = create_new_node();
			tmp = tmp->next;
		}
		i++;
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	stack_a = fill_stack(argc, argv, stack_a);
	if (stack_a == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	stack_push(&stack_a, &stack_b);
	// stack_iter(stack_a);
	// printf("---------\n");
	// stack_iter(stack_b);
	return(0);
}