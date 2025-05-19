/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 06:00:38 by isel-bar          #+#    #+#             */
/*   Updated: 2025/05/18 17:19:46 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sorts a stack with 2 elements
** @param stack Stack to sort
*/
void	sort_stack_size_2(t_stack *stack)
{
	if (stack->top < 1)
		return ;
	if (stack->values[0] < stack->values[1])
		swap_stack_a(stack);
}

/*
** Sorts a stack with 3 elements
** @param stack Stack to sort
*/
void	sort_stack_size_3(t_stack *stack)
{
	int	top;
	int	middle;
	int	bottom;

	if (stack->top < 2)
		return ;
	top = stack->values[stack->top];
	middle = stack->values[stack->top - 1];
	bottom = stack->values[stack->top - 2];
	if (top > middle && middle > bottom)
	{
		swap_stack_a(stack);
		reverse_rotate_stack_a(stack);
	}
	else if (top > bottom && bottom > middle)
		rotate_stack_a(stack);
	else if (middle > top && top > bottom)
		reverse_rotate_stack_a(stack);
	else if (middle > bottom && bottom > top)
	{
		swap_stack_a(stack);
		rotate_stack_a(stack);
	}
	else if (bottom > top && top > middle)
		swap_stack_a(stack);
}

/*
** Sorts a stack with up to 5 elements
** @param stack_a Stack A to sort
** @param stack_b Stack B for temporary storage
*/
void	sort_stack_size_5(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		rotate_to_value(stack_a, find_min(stack_a));
		push_to_stack_b(stack_a, stack_b);
		i++;
	}
	if (stack_a->top == 2)
		sort_stack_size_3(stack_a);
	else
		sort_stack_size_2(stack_a);
	while (stack_b->top >= 0)
		push_to_stack_a(stack_a, stack_b);
}

/*
** Performs radix sort on the stack
** @param stack_a Pointer to stack A
** @param stack_b Pointer to stack B
*/
void	sort_with_radix(t_stack *stack_a, t_stack *stack_b)
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
			if (get_bit_at_position(stack_a->values[stack_a->top], i))
				rotate_stack_a(stack_a);
			else
				push_to_stack_b(stack_a, stack_b);
			j++;
		}
		while (stack_b->top >= 0)
			push_to_stack_a(stack_a, stack_b);
		i++;
	}
}

/*
** Main sorting function that handles all cases
** @param stack_a Pointer to stack A
** @param stack_b Pointer to stack B
*/
void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	rank_stack(stack_a);
	if (stack_a->top == 1)
		sort_stack_size_2(stack_a);
	else if (stack_a->top == 2)
		sort_stack_size_3(stack_a);
	else if (stack_a->top <= 4)
		sort_stack_size_5(stack_a, stack_b);
	else
		sort_with_radix(stack_a, stack_b);
}
