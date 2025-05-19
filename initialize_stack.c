/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 06:00:38 by isel-bar          #+#    #+#             */
/*   Updated: 2025/05/18 17:14:09 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Initializes stack A and B with the given arguments
** @param ac Number of arguments
** @param av Array of arguments
** @param stack_a Pointer to stack A
** @param stack_b Pointer to stack B
** @return 1 if successful, 0 if error
*/
int	initialize_stack(int ac, char **av, t_stack *stack_a, t_stack *stack_b)
{
	int	error;

	if (ac < 2)
		return (0);
	stack_a->top = -1;
	stack_b->top = -1;
	ac--;
	while (ac > 0)
	{
		if (!is_number(av[ac]))
			return (0);
		stack_a->values[++stack_a->top] = safe_atoi(av[ac], &error);
		if (error)
			return (0);
		ac--;
	}
	if (has_duplicates(stack_a))
		return (0);
	return (1);
}

/*
** Frees allocated memory for stacks
** @param stack_a Pointer to stack A
** @param stack_b Pointer to stack B
*/
void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->values);
	free(stack_a);
	free(stack_b->values);
	free(stack_b);
}
