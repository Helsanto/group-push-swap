/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_disorder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misasant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:56:29 by misasant          #+#    #+#             */
/*   Updated: 2026/02/16 16:57:23 by misasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	get_disorder(t_stack *stack)
{
	t_node	*i;
	t_node	*j;
	int		mistakes;
	int		total_pairs;

	if (stack->size < 2)
		return (0.0);
	mistakes = 0;
	total_pairs = stack->size * (stack->size - 1) / 2;
	i = stack->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return ((double)mistakes / (double)total_pairs);
}
