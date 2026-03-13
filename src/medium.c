/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkordas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:57:39 by gkordas           #+#    #+#             */
/*   Updated: 2026/03/12 09:57:42 by gkordas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_stack *stack)
{
	int		min_pos;
	int		min_val;
	int		i;
	t_node	*tmp;

	min_pos = 0;
	i = 0;
	tmp = stack->top;
	min_val = tmp->value;
	while (tmp)
	{
		if (tmp->value < min_val)
		{
			min_val = tmp->value;
			min_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_pos);
}

static void	push_min_to_b(t_data *d)
{
	int	min_pos;

	min_pos = find_min_pos(d->a);
	if (min_pos <= d->a->size / 2)
	{
		while (min_pos-- > 0)
			ra(d);
	}
	else
	{
		min_pos = d->a->size - min_pos;
		while (min_pos-- > 0)
			rra(d);
	}
	pb(d);
}

void	medium_sort(t_data *d)
{
	while (d->a->size > 3)
		push_min_to_b(d);
	simple_sort(d);
	while (d->b->size > 0)
		pa(d);
}
