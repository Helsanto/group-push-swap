/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkordas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:01:07 by gkordas           #+#    #+#             */
/*   Updated: 2026/03/12 10:01:14 by gkordas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_pos(t_stack *s)
{
	t_node	*tmp;
	int		min;
	int		pos;
	int		i;

	tmp = s->top;
	min = tmp->value;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

static void	sort_three(t_data *d)
{
	int	a;
	int	b;
	int	c;

	a = d->a->top->value;
	b = d->a->top->next->value;
	c = d->a->bottom->value;
	if (a > b && a > c)
		ra(d);
	else if (b > a && b > c)
		rra(d);
	if (d->a->top->value > d->a->top->next->value)
		sa(d);
}

static void	push_min_to_b(t_data *d)
{
	int	pos;

	while (d->a->size > 3)
	{
		pos = get_min_pos(d->a);
		while (pos-- > 0)
			ra(d);
		pb(d);
	}
}

void	simple_sort(t_data *d)
{
	if (d->a->size == 1)
		return ;
	if (d->a->size == 2)
	{
		if (d->a->top->value > d->a->top->next->value)
			sa(d);
		return ;
	}
	if (d->a->size == 3)
	{
		sort_three(d);
		return ;
	}
	push_min_to_b(d);
	sort_three(d);
	while (d->b->size > 0)
		pa(d);
}
