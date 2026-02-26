
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

int ft_sqrt(int n)
{
    int i; 
    i = 1;

    while (i * i <= n)
        i++;
    return i - 1;
}

int find_position_in_chunk(t_stack *a, int min, int max)
{
    t_node *current;
    int position;

    current = a->top;
    position = 0;

    while (current)
    {
        if (current->index >= min && current->index <= max)
            return (position);
        current = current->next;
        position++;
    }
    return (-1);
}

int	find_max_pos(t_stack *b)
{
	int		pos;
	int		i;
	int		max;
	t_node	*cur;

	pos = 0;
	i = 0;
	max = b->top->index;
	cur = b->top;
	while (cur)
	{
		if (cur->index > max)
		{
			max = cur->index;
			pos = i;
		}
		cur = cur->next;
		i++;
	}
	return (pos);
}

void	move_back_to_a(t_stack *a, t_stack *b)
{
	int	max_pos;
	t_node	*current;
	int	i;
	int	max;

	while (b->size > 0)
	{
		// znajdź największy element w B
		max = b->top->index;
		max_pos = 0;
		current = b->top;
		i = 0;
		while (current)
		{
			if (current->index > max)
			{
				max = current->index;
				max_pos = i;
			}
			current = current->next;
			i++;
		}

		// wybierz krótszą drogę
		if (max_pos <= b->size / 2)
			while (max_pos-- > 0)
				rb(b);
		else
			while (max_pos++ < b->size)
				rrb(b);

		// przenieś największy do A
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