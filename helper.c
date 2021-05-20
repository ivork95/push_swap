/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/20 19:01:01 by ivork         #+#    #+#                 */
/*   Updated: 2021/05/20 20:22:10 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdlib.h>

t_stack	*stack_last(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	stack_add_back(t_stack **lst, t_stack *new)
{
	if (!*lst)
		*lst = new;
	else
		stack_last(*lst)->next = new;
}


void	stack_add_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

void	stack_clear(t_stack **lst, void (*del)(void*))
{
	t_stack *current;

	current = *lst;
	if (current->next != NULL)
		stack_clear(&current->next, del);
	del(current->content);
	free(current);
	*lst = 0;
}

void	stack_delone(t_stack *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

void	stack_delone(t_stack *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

void	stack_iter(t_stack *lst)
{
	t_stack *current;

	current = lst;
	while (current)
	{
		printf("%d\n", current->num);
		current = current->next;
	}
}

