/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 06:19:35 by isel-bar          #+#    #+#             */
/*   Updated: 2025/04/18 06:19:44 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Copies all values from a stack to an array
 */
void	fill_array(t_stack *stack, int *array)
{
	int	i;

	i = 0;
	while (i <= stack->top)
	{
		array[i] = stack->array[i];
		i++;
	}
}

/**
 * Creates a sorted copy of the stack values
 */
void	create_sorted_array(t_stack *stack_a, int *sorted)
{
	int	i;
	int	j;
	int	temp;

	fill_array(stack_a, sorted);
	i = 0;
	while (i < stack_a->top)
	{
		j = 0;
		while (j < stack_a->top - i)
		{
			if (sorted[j] > sorted[j + 1])
			{
				temp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

/**
 * Replaces each value in the stack with its rank
 * (position in the sorted array)
 */
void	assign_ranks(t_stack *stack)
{
	int	*sorted;
	int	i;
	int	j;

	sorted = malloc(sizeof(int) * (stack->top + 1));
	if (!sorted)
		return ;
	create_sorted_array(stack, sorted);
	i = 0;
	while (i <= stack->top)
	{
		j = 0;
		while (j <= stack->top)
		{
			if (stack->array[i] == sorted[j])
			{
				stack->array[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(sorted);
}

/**
 * Calculates the number of bits needed to represent
 * the maximum value in the stack
 */
int	get_max_bits(t_stack *stack)
{
	int	max;
	int	max_bits;

	max = find_max(stack);
	max_bits = 0;
	while (max != 0)
	{
		max /= 2;
		max_bits++;
	}
	return (max_bits);
}

/**
 * Gets the bit value at a specific position for a number
 */
int	get_bit_at_position(int num, int position)
{
	while (position > 0)
	{
		num /= 2;
		position--;
	}
	return (num % 2);
}