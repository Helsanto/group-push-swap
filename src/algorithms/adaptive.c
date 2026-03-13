/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkordas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:22:49 by gkordas           #+#    #+#             */
/*   Updated: 2026/02/27 14:22:56 by gkordas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Adaptive sort: choose strategy based on disorder
void	adaptive_sort(t_stack *a, t_stack *b)
{
	double		disorder;
	int			size;

	if (!a || !a->top)
		return ;
	size = a->size;
	disorder = get_disorder(a);
	if (size <= 3)
	{
		simple_sort(a, b);
	}
	else if (disorder < 0.1)
	{
		medium_sort(a, b);
	}
	else
	{
		complex_sort(a, b);
	}
}
