/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 06:00:38 by isel-bar          #+#    #+#             */
/*   Updated: 2025/05/18 17:14:09 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Swaps the top two elements of stack A
** @param stack_a Pointer to stack A
*/
void	swap_stack_a(t_stack *stack_a)
{
	int	temp;

	if (stack_a->top < 1)
		return ;
	temp = stack_a->values[stack_a->top];
	stack_a->values[stack_a->top] = stack_a->values[stack_a->top - 1];
	stack_a->values[stack_a->top - 1] = temp;
	write(1, "sa\n", 3);
}

/*
** Rotates stack A (top element goes to bottom)
** @param stack_a Pointer to stack A
*/
void	rotate_stack_a(t_stack *stack_a)
{
	int	temp;
	int	i;

	if (stack_a->top < 1)
		return ;
	temp = stack_a->values[stack_a->top];
	i = stack_a->top;
	while (i > 0)
	{
		stack_a->values[i] = stack_a->values[i - 1];
		i--;
	}
	stack_a->values[0] = temp;
	write(1, "ra\n", 3);
}

/*
** Reverse rotates stack A (bottom element goes to top)
** @param stack_a Pointer to stack A
*/
void	reverse_rotate_stack_a(t_stack *stack_a)
{
	int	temp;
	int	i;

	i = 0;
	if (stack_a->top < 1)
		return ;
	temp = stack_a->values[0];
	while (i < stack_a->top)
	{
		stack_a->values[i] = stack_a->values[i + 1];
		i++;
	}
	stack_a->values[stack_a->top] = temp;
	write(1, "rra\n", 4);
}

/*
** Pushes the top element from stack B to stack A
** @param stack_a Pointer to stack A
** @param stack_b Pointer to stack B
*/
void	push_to_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->top < 0)
		return ;
	stack_a->top++;
	stack_a->values[stack_a->top] = stack_b->values[stack_b->top];
	stack_b->top--;
	write(1, "pa\n", 3);
}

/*
** Pushes the top element from stack A to stack B
** @param stack_a Pointer to stack A
** @param stack_b Pointer to stack B
*/
void	push_to_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top < 0)
		return ;
	stack_b->top++;
	stack_b->values[stack_b->top] = stack_a->values[stack_a->top];
	stack_a->top--;
	write(1, "pb\n", 3);
}
