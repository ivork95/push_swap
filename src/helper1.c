/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper1.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 14:39:47 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/31 17:13:42 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	check_duplicates(t_stack *stack_a)
{
	t_stack	*current;

	while (stack_a)
	{
		current = stack_a->next;
		while (current)
		{
			if (current->num == stack_a->num)
				err_func();
			current = current->next;
		}
		stack_a = stack_a->next;
	}
}

int	check_argument(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	if (str[i] == '-' && str[i + 1] != '\0')
		i++;
	while (*str == '0')
		str++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i > 9 && ft_atoi(str) == 0)
		return (0);
	return (1);
}

t_stack	*create_new_node(void)
{
	t_stack	*first;

	first = (t_stack *)malloc(sizeof(t_stack));
	first->next = NULL;
	return (first);
}

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack	*tmp;
	t_stack	*stack_a;
	int		i;

	i = 1;
	tmp = create_new_node();
	stack_a = tmp;
	while (i < argc)
	{
		if (!check_argument(argv[i]))
			return (NULL);
		tmp->num = ft_atoi(argv[i]);
		tmp->next = NULL;
		if (i < argc - 1)
		{
			tmp->next = create_new_node();
			tmp = tmp->next;
		}
		i++;
	}
	check_duplicates(stack_a);
	return (stack_a);
}

void	err_func(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
