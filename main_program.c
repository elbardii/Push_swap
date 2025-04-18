/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 06:00:38 by isel-bar          #+#    #+#             */
/*   Updated: 2025/04/18 11:12:54 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Main function for the push_swap program
 * Processes arguments, initializes stacks, and sorts integers
 */
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (0);
	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
	{
		free(stack_a);
		return (0);
	}
	stack_a->array = malloc(sizeof(int) * (ac - 1));
	if (!stack_a->array)
	{
		free(stack_a);
		free(stack_b);
		return (0);
	}
	stack_b->array = malloc(sizeof(int) * (ac - 1));
	if (!stack_b->array)
	{
		free(stack_a->array);
		free(stack_a);
		free(stack_b);
		return (0);
	}
	if (!init_stack(ac, av, stack_a, stack_b))
	{
		free_stacks(stack_a, stack_b);
		print_error();
	}
	if (!is_sorted(stack_a))
		sort(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}