/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkordas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:25:45 by gkordas           #+#    #+#             */
/*   Updated: 2026/02/27 14:25:49 by gkordas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Find the position in A where the element should be inserted
int	find_insert_position(t_stack *a, int index)
{
	t_node	*cur;
	int		pos;

	cur = a->top;
	pos = 0;
	while (cur)
	{
		if (index < cur->index)
			return (pos);
		pos++;
		cur = cur->next;
	}
	return (pos);
}

// Rotate A so that the target position becomes the top
void	rotate_a_to_pos(t_stack *a, int pos)
{
	if (pos <= a->size / 2)
		while (pos-- > 0)
			ra(a);
	else
	{
		pos = a->size - pos;
		while (pos-- > 0)
			rra(a);
	}
}

// Find the position of the smallest element in A
int	find_min_position(t_stack *a)
{
	t_node	*cur;
	int		pos;
	int		best_pos;
	int		min;

	cur = a->top;
	pos = 0;
	best_pos = 0;
	min = cur->index;
	while (cur)
	{
		if (cur->index < min)
		{
			min = cur->index;
			best_pos = pos;
		}
		pos++;
		cur = cur->next;
	}
	return (best_pos);
}

// Rotate A so that the smallest element becomes the top
void	rotate_min_to_top(t_stack *a)
{
	int	pos;

	if (!a || !a->top)
		return ;
	pos = find_min_position(a);
	if (pos <= a->size / 2)
		while (pos-- > 0)
			ra(a);
	else
	{
		pos = a->size - pos;
		while (pos-- > 0)
			rra(a);
	}
}

// Main insertion-sort-based simple algorithm (O(n²))
void	simple_sort(t_stack *a, t_stack *b)
{
	int	pos;
	int	index;

	if (!a || !b || !a->top || !b->top)
		return ;
	while (a->size > 0)
		pb(a, b);
	while (b->size > 0)
	{
		index = b->top->index;
		pos = find_insert_position(a, index);
		rotate_a_to_pos(a, pos);
		pa(a, b);
	}
	rotate_min_to_top(a);
}
