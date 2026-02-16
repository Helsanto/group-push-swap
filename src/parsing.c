/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misasant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:20:40 by misasant          #+#    #+#             */
/*   Updated: 2026/02/16 16:26:15 by misasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	is_valid_number(char *str)
{
	int		i;
	long	num;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

int	has_duplicates(t_stack *stack)
{
	t_node	*current;
	t_node	*checker;

	current = stack->top;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

static int	process_split(char **split, t_stack *stack_a)
{
	int		j;
	t_node	*new;

	j = 0;
	while (split[j])
	{
		if (!is_valid_number(split[j]))
			return (0);
		new = node_new((int)ft_atol(split[j]));
		if (!new)
			return (0);
		stack_add_back(stack_a, new);
		j++;
	}
	return (1);
}

int	parse_arguments(int argc, char **argv, t_stack *stack_a)
{
	int		i;
	char	**split;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (0);
		if (!process_split(split, stack_a))
		{
			free_split(split);
			return (0);
		}
		free_split(split);
		i++;
	}
	if (has_duplicates(stack_a))
		return (0);
	return (1);
}
