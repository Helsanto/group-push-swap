/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkordas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:23:56 by gkordas           #+#    #+#             */
/*   Updated: 2026/02/27 14:23:59 by gkordas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*stack_to_array(t_node *a, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (a && i < size)
	{
		arr[i++] = a->value;
		a = a->next;
	}
	return (arr);
}

/*
** Simple bubble sort (O(n²)).
*/
void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	find_index(int *sorted, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	assign_indexes(t_node *a, int *sorted, int size)
{
	int	idx;

	while (a)
	{
		idx = find_index(sorted, size, a->value);
		a->index = idx;
		a = a->next;
	}
}

void	normalize_stack(t_node *a, int size)
{
	int	*arr;

	if (!a || size <= 0)
		return ;
	arr = stack_to_array(a, size);
	if (!arr)
		return ;
	bubble_sort(arr, size);
	assign_indexes(a, arr, size);
	free(arr);
}
