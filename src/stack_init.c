/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misasant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:20:48 by misasant          #+#    #+#             */
/*   Updated: 2026/02/16 15:46:10 by misasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_node *node_new(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack *init_stack(void)
{
	t_stack	*init;

	init = malloc(sizeof(t_stack));
	if (!init)
		return (NULL);
	init->top = NULL;
	init->bottom = NULL;
	init->size = 0;
	return (init);
}

void	stack_add_back(t_stack *stack, t_node *new)
{
	if (!stack->top)
	{
		stack->top = new;
		stack->bottom = new;
		stack->size = 1;
		return ;
	}
	stack->bottom->next = new;
	new->prev = stack->bottom;
	stack->bottom = new;
	stack->size++;
}
