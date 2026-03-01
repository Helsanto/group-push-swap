/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkordas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:23:11 by gkordas           #+#    #+#             */
/*   Updated: 2026/02/27 14:23:14 by gkordas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// Return the highest index in the stack
int	get_max_index(t_stack *a)
{
	int		max;
	t_node	*tmp;

	if (!a || !a->top)
		return (0);
	tmp = a->top;
	max = tmp->index;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

// Count how many bits are needed to represent the largest index
int	count_bits(t_stack *a)
{
	int	max_index;
	int	bits;

	max_index = get_max_index(a);
	bits = 0;
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

// Process a single bit for radix sort
void	process_bit(t_stack *a, t_stack *b, int bit)
{
	int	i;
	int	total;

	if (!a || !a->top)
		return ;
	i = 0;
	total = a->size;
	while (i < total)
	{
		if (((a->top->index >> bit) & 1) == 0)
			pb(a, b);
		else
			ra(a);
		i++;
	}
	while (b->size > 0)
		pa(a, b);
}

// Main radix sort function
void	complex_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	bit;

	normalize(a);
	max_bits = count_bits(a);
	bit = 0;
	while (bit < max_bits)
	{
		process_bit(a, b, bit);
		bit++;
	}
}
