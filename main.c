/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 06:00:38 by isel-bar          #+#    #+#             */
/*   Updated: 2025/05/18 17:19:46 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Allocates memory for stacks
** @param ac Number of arguments
** @param stack_a Pointer to stack A
** @param stack_b Pointer to stack B
** @return 1 if successful, 0 if error
*/
int	allocate_stacks(int ac, t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = malloc(sizeof(t_stack));
	if (!(*stack_a))
		return (0);
	*stack_b = malloc(sizeof(t_stack));
	if (!(*stack_b))
	{
		free(*stack_a);
		return (0);
	}
	(*stack_a)->values = malloc(sizeof(int) * (ac - 1));
	if (!(*stack_a)->values)
	{
		free(*stack_a);
		free(*stack_b);
		return (0);
	}
	(*stack_b)->values = malloc(sizeof(int) * (ac - 1));
	if (!(*stack_b)->values)
	{
		free((*stack_a)->values);
		free(*stack_a);
		free(*stack_b);
		return (0);
	}
	return (1);
}

/*
** Main function that handles initialization and sorting
** @param ac Number of arguments
** @param av Array of arguments
** @return 0 on successful execution
*/
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	if (!allocate_stacks(ac, &stack_a, &stack_b))
		return (0);
	if (!initialize_stack(ac, av, stack_a, stack_b))
	{
		free_stacks(stack_a, stack_b);
		exit_with_error();
	}
	sort_stack(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}
