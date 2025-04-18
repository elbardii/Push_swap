/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 06:21:30 by isel-bar          #+#    #+#             */
/*   Updated: 2025/04/18 11:49:21 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Validates if a string contains only a valid integer representation
 */
int	is_number(char *str)
{
	if (!str || !*str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

/**
 * Checks if there are any duplicate values in the stack
 */
int	has_duplicates(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i <= stack->top)
	{
		j = i + 1;
		while (j <= stack->top)
		{
			if (stack->array[i] == stack->array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * Checks if the stack is already sorted in ascending order
 */
int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->top)
	{
		if (stack->array[i] > stack->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

/**
 * Converts string to integer with overflow checking
 */
int	ft_atoi(char *str, int *error)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	*error = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		result = result * 10 + (*str - '0');
		if ((sign == 1 && result > 2147483647)
			|| (sign == -1 && result > 2147483648))
		{
			*error = 1;
			return (0);
		}
		str++;
	}
	return ((int)(result * sign));
}

/**
 * Prints error message and exits the program
 */
int	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}