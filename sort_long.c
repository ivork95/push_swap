/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_long.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 15:11:00 by ivork         #+#    #+#                 */
/*   Updated: 2021/06/10 19:52:04 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>


void read_tree(t_tree *tree, int **arr, int x)
{
	if (!tree)
		return ;
	if (tree->left)
		read_tree(tree->left, arr, x);
	*arr[x] = tree->num;
	x++;
	if (tree->right)
		read_tree(tree->right, arr, x);
}


void	sort_long(t_stack **stack, t_tree *tree, int len)
{
	int *arr;
	t_stack *current;
	int x;

	arr = malloc(sizeof(int) * len);
	current = *stack;
	x = 0;
	while (current)
	{
		arr[x] = current->num;
		current = current->next;
		x++;
	}
	get_chunck(arr, len);

}