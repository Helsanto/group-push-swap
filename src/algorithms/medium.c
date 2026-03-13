/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkordas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:23:26 by gkordas           #+#    #+#             */
/*   Updated: 2026/02/27 14:23:28 by gkordas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

void	move_back_to_a(t_stack *a, t_stack *b)
{
	int	max_pos;

	while (b->size > 0)
	{
		max_pos = find_max_pos(b);
		rotate_stack(b, max_pos);
		pa(a, b);
	}
}

void	push_chunk_to_b(t_stack *a, t_stack *b, int min, int max)
{
	int	count;
	int	chunk_size;
	int	pos;
	int	middle;

	count = 0;
	chunk_size = max - min + 1;
	middle = (min + max) / 2;
	while (count < chunk_size)
	{
		pos = find_position_in_chunk(a, min, max);
		if (pos == 0)
		{
			pb(a, b);
			count++;
			if (b->top->index <= middle)
				rb(b);
		}
		else if (pos <= a->size / 2)
			ra(a);
		else
			rra(a);
	}
}

void	medium_sort(t_stack *a, t_stack *b)
{
	int	total_size;
	int	chunk_size;
	int	min_index;
	int	max_index;

	total_size = a->size;
	chunk_size = ft_sqrt(total_size) + 1;
	min_index = 0;
	max_index = chunk_size - 1;
	while (min_index < total_size)
	{
		if (max_index >= total_size)
			max_index = total_size - 1;
		push_chunk_to_b(a, b, min_index, max_index);
		min_index += chunk_size;
		max_index += chunk_size;
	}
	move_back_to_a(a, b);
}
