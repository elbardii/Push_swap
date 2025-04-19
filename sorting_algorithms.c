/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 06:18:56 by isel-bar          #+#    #+#             */
/*   Updated: 2025/04/19 11:33:43 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Sorts a stack with 2 elements
 */
void	sort_two(t_stack *stack)
{
	if (stack->array[0] < stack->array[1])
		swap_a(stack);
}

/**
 * Sorts a stack with 3 elements
 */
void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->array[stack->top];
	b = stack->array[stack->top - 1];
	c = stack->array[stack->top - 2];
	if (a > b && b > c)
	{
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	else if (a > c && c > b)
		rotate_a(stack);
	else if (b > a && a > c)
		reverse_rotate_a(stack);
	else if (b > c && c > a)
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if (c > a && a > b)
		swap_a(stack);
}

/**
 * Sorts a stack with 5 or fewer elements
 */
void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		rotate_to_value(stack_a, find_min(stack_a));
		push_b(stack_a, stack_b);
		i++;
	}
	if (stack_a->top == 2)
		sort_three(stack_a);
	else
		sort_two(stack_a);
	while (stack_b->top >= 0)
		push_a(stack_a, stack_b);
}

/**
 * Performs radix sort on the stack
 */
void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	i = 0;
	max_bits = get_max_bits(stack_a);
	size = stack_a->top + 1;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (get_bit_at_position(stack_a->array[stack_a->top], i))
				push_b(stack_a, stack_b);
			else
				rotate_a(stack_a);
			j++;
		}
		while (stack_b->top >= 0)
			push_a(stack_a, stack_b);
		i++;
	}
}

/**
 * Main sorting function - chooses appropriate algorithm
 * based on the number of elements
 */
void	sort(t_stack *stack_a, t_stack *stack_b)
{
	assign_ranks(stack_a);
	if (stack_a->top == 1)
		sort_two(stack_a);
	else if (stack_a->top == 2)
		sort_three(stack_a);
	else if (stack_a->top <= 4)
		sort_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}
