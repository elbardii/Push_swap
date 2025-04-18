/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 06:16:46 by isel-bar          #+#    #+#             */
/*   Updated: 2025/04/18 11:12:54 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Initializes stack A with integers from command line arguments
 * and performs basic validation
 */
int	init_stack(int ac, char **av, t_stack *stack_a, t_stack *stack_b)
{
	int	error;
	int	i;

	if (ac < 2)
		return (0);
	stack_a->top = -1;
	stack_b->top = -1;
	i = 1;
	while (i < ac)
	{
		if (!is_number(av[i]))
			return (0);
		stack_a->array[++stack_a->top] = ft_atoi_secure(av[i], &error);
		if (error)
			return (0);
		i++;
	}
	if (has_duplicates(stack_a))
		return (0);
	return (1);
}

/**
 * Frees allocated memory for both stacks
 */
void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a && stack_a->array)
		free(stack_a->array);
	if (stack_a)
		free(stack_a);
	if (stack_b && stack_b->array)
		free(stack_b->array);
	if (stack_b)
		free(stack_b);
}
