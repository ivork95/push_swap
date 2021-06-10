/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 17:19:32 by ivork         #+#    #+#                 */
/*   Updated: 2021/06/09 17:15:36 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "includes/push_swap.h"

t_tree	*create_new_tree(int x)
{
	t_tree	*first;

	first = (t_tree*)malloc(sizeof(t_tree));
	first->num = x;
	first->left = NULL;
	first->right = NULL;
	return (first);
}

t_tree *fill_tree(t_stack *stack)
{
	t_tree *tree;
	t_tree *tmp;

	tree = create_new_tree(stack->num);
	tmp = tree;
	stack = stack->next;
	while(stack != NULL)
	{
		printf("stack = %d\n", stack->num);
		printf("tmp = %d\n", tmp->num);
		if (stack->num > tmp->num)
		{
			if (tmp->right == NULL)
			{
				tree->right = create_new_tree(stack->num);
				printf("ADD right = %d\n", stack->num);
				stack = stack->next;
				tmp = tree;
			}
			else
			{
				tmp = tmp->right;
				printf("R++\n");
			}
		}
		else if (stack->num < tmp->num)
		{
			if (tmp->left == NULL)
			{
				tree->left = create_new_tree(stack->num);
				printf("ADD left = %d\n", stack->num);
				stack = stack->next;
				tmp = tree;
			}
			else
			{
				tmp = tmp->left;
				printf("L++\ntmp = %d\n", tmp->num);
			}
		}
	}
	return (tree);
}