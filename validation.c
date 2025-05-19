/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 06:00:38 by isel-bar          #+#    #+#             */
/*   Updated: 2025/05/18 17:14:09 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Checks if the string is a valid number
** @param str String to check
** @return 1 if it's a valid number, 0 if not
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

/*
** Checks for duplicate values in the stack
** @param stack Stack to check
** @return 1 if duplicates found, 0 if not
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
			if (stack->values[i] == stack->values[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
** Checks if the stack is already sorted (descending order)
** @param stack Stack to check
** @return 1 if sorted, 0 if not
*/
int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->top)
	{
		if (stack->values[i] < stack->values[i + 1])
			return (0);
		i++;
	}
	return (1);
}

/*
** Converts string to integer with error checking
** @param str String to convert
** @param error Pointer to error flag
** @return The integer value
*/
int	safe_atoi(char *str, int *error)
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
		if ((sign == 1 && result > 2147483647) || (sign == -1
				&& result > 2147483648))
		{
			*error = 1;
			return (0);
		}
		str++;
	}
	return ((int)(result * sign));
}

/*
** Prints error message and exits
** @return Always returns 1
*/
int	exit_with_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
