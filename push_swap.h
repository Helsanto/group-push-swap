/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misasant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:03:49 by misasant          #+#    #+#             */
/*   Updated: 2026/02/16 15:03:54 by misasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

typedef struct s_node
{
	int             value;
	int             index;
	struct s_node   *next;
	struct s_node   *prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

/*
** ========== STACK INIT / UTILS ==========
*/
t_node	*node_new(int value);
t_stack	*init_stack(void);
void	stack_add_back(t_stack *stack, t_node *new_node);
void	free_stack(t_stack *stack);

/*
** ========== PARSING ==========
*/
long	ft_atol(const char *str);
int		is_valid_number(char *str);
int		has_duplicates(t_stack *stack);
void	free_split(char **split);
int		parse_arguments(int argc, char **argv, t_stack *stack_a);

/*
** ========== DISORDER METRIC ==========
*/
double	get_disorder(t_stack *stack);

#endif
