/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 06:00:38 by isel-bar          #+#    #+#             */
/*   Updated: 2025/05/18 17:14:09 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Finds the position of a value in the stack
** @param stack Stack to search
** @param value Value to find
** @return Position of the value (-1 if not found)
*/
int	find_position(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (i <= stack->top)
	{
		if (stack->values[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

/*
** Finds the maximum value in the stack
** @param stack Stack to search
** @return Maximum value
*/
int	find_max(t_stack *stack)
{
	int	max;
	int	i;

	i = 1;
	max = stack->values[0];
	while (i <= stack->top)
	{
		if (max < stack->values[i])
			max = stack->values[i];
		i++;
	}
	return (max);
}

/*
** Finds the minimum value in the stack
** @param stack Stack to search
** @return Minimum value
*/
int	find_min(t_stack *stack)
{
	int	min;
	int	i;

	if (stack->top < 0)
		return (0);
	min = stack->values[0];
	i = 1;
	while (i <= stack->top)
	{
		if (stack->values[i] < min)
			min = stack->values[i];
		i++;
	}
	return (min);
}

/*
** Rotates the stack until a specific value is at the top
** @param stack Stack to rotate
** @param value Value to bring to top
*/
void	rotate_to_value(t_stack *stack, int value)
{
	int	pos;

	pos = find_position(stack, value);
	if (pos <= stack->top / 2)
	{
		while (stack->values[stack->top] != value)
			reverse_rotate_stack_a(stack);
	}
	else
	{
		while (stack->values[stack->top] != value)
			rotate_stack_a(stack);
	}
}
