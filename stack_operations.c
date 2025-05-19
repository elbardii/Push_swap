/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 06:00:38 by isel-bar          #+#    #+#             */
/*   Updated: 2025/05/18 17:14:09 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Copies stack values to an array
** @param stack Source stack
** @param array Destination array
*/
void	copy_stack_to_array(t_stack *stack, int *array)
{
	int	i;

	i = 0;
	while (i <= stack->top)
	{
		array[i] = stack->values[i];
		i++;
	}
}

/*
** Creates a sorted array from stack values
** @param stack Stack to sort
** @param sorted_array Array to store sorted values
*/
void	create_sorted_array(t_stack *stack, int *sorted_array)
{
	int	i;
	int	j;
	int	temp;

	copy_stack_to_array(stack, sorted_array);
	i = 0;
	while (i < stack->top)
	{
		j = 0;
		while (j < stack->top - i)
		{
			if (sorted_array[j] > sorted_array[j + 1])
			{
				temp = sorted_array[j];
				sorted_array[j] = sorted_array[j + 1];
				sorted_array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

/*
** Assigns index values to stack elements based on their sorted position
** @param stack Stack to rank
*/
void	rank_stack(t_stack *stack)
{
	int	*sorted_array;
	int	i;
	int	j;

	sorted_array = malloc(sizeof(int) * (stack->top + 1));
	if (!sorted_array)
		return ;
	create_sorted_array(stack, sorted_array);
	i = 0;
	while (i <= stack->top)
	{
		j = 0;
		while (j <= stack->top)
		{
			if (stack->values[i] == sorted_array[j])
			{
				stack->values[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(sorted_array);
}

/*
** Gets the maximum number of bits needed for radix sort
** @param stack Stack to analyze
** @return Number of bits
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

/*
** Gets the bit value at a specific position
** @param number Number to check
** @param position Bit position
** @return Bit value (0 or 1)
*/
int	get_bit_at_position(int number, int position)
{
	while (position > 0)
	{
		number /= 2;
		position--;
	}
	return (number % 2);
}
