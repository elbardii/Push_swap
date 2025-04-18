/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 06:20:46 by isel-bar          #+#    #+#             */
/*   Updated: 2025/04/18 09:08:42 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Finds the position of a specific value in the stack
 */
int	find_position(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (i <= stack->top)
	{
		if (stack->array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * Finds the maximum value in the stack
 */
int	find_max(t_stack *stack)
{
	int	max;
	int	i;

	i = 1;
	max = stack->array[0];
	while (i <= stack->top)
	{
		if (max < stack->array[i])
			max = stack->array[i];
		i++;
	}
	return (max);
}

/**
 * Finds the minimum value in the stack
 */
int	find_min(t_stack *stack)
{
	int	min;
	int	i;

	if (stack->top < 0)
		return (0);
	min = stack->array[0];
	i = 1;
	while (i <= stack->top)
	{
		if (stack->array[i] < min)
			min = stack->array[i];
		i++;
	}
	return (min);
}

/**
 * Rotates the stack until the specified value is at the top
 */
void	rotate_to_value(t_stack *stack, int value)
{
	int	pos;

	pos = find_position(stack, value);
	if (pos <= stack->top / 2)
	{
		while (stack->array[stack->top] != value)
			reverse_rotate_a(stack);
	}
	else
	{
		while (stack->array[stack->top] != value)
			rotate_a(stack);
	}
}