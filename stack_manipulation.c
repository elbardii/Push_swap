/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 06:18:11 by isel-bar          #+#    #+#             */
/*   Updated: 2025/04/19 11:28:42 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Swaps the top two elements of stack A
 */
void	swap_a(t_stack *stack_a)
{
	int	temp;

	if (stack_a->top < 1)
		return ;
	temp = stack_a->array[stack_a->top];
	stack_a->array[stack_a->top] = stack_a->array[stack_a->top - 1];
	stack_a->array[stack_a->top - 1] = temp;
	write(1, "sa\n", 3);
}

/**
 * Rotates stack A - shifts all elements up by one position
 * The top element becomes the bottom element
 */
void	rotate_a(t_stack *stack_a)
{
	int	temp;
	int	i;

	if (stack_a->top < 1)
		return ;
	temp = stack_a->array[stack_a->top];
	i = stack_a->top;
	while (i > 0)
	{
		stack_a->array[i] = stack_a->array[i - 1];
		i--;
	}
	stack_a->array[0] = temp;
	write(1, "ra\n", 3);
}

/**
 * Reverse rotates stack A - shifts all elements down by one position
 * The bottom element becomes the top element
 */
void	reverse_rotate_a(t_stack *stack_a)
{
	int	temp;
	int	i;

	i = 0;
	if (stack_a->top < 1)
		return ;
	temp = stack_a->array[0];
	while (i < stack_a->top)
	{
		stack_a->array[i] = stack_a->array[i + 1];
		i++;
	}
	stack_a->array[stack_a->top] = temp;
	write(1, "rra\n", 4);
}

/**
 * Pushes the top element from stack B to stack A
 */
void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->top < 0)
		return ;
	stack_a->top++;
	stack_a->array[stack_a->top] = stack_b->array[stack_b->top];
	stack_b->top--;
	write(1, "pa\n", 3);
}

/**
 * Pushes the top element from stack A to stack B
 */
void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top < 0)
		return ;
	stack_b->top++;
	stack_b->array[stack_b->top] = stack_a->array[stack_a->top];
	stack_a->top--;
	write(1, "pb\n", 3);
}
