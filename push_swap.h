/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:10:17 by aybareic          #+#    #+#             */
/*   Updated: 2025/05/18 17:19:46 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*values;
	int	top;
}		t_stack;

/*
** Initializes stack A and B with the given arguments
** @param ac Number of arguments
** @param av Array of arguments
** @param stack_a Pointer to stack A
** @param stack_b Pointer to stack B
** @return 1 if successful, 0 if error
*/
int		initialize_stack(int ac, char **av, t_stack *stack_a, t_stack *stack_b);

/*
** Checks if the string is a valid number
** @param str String to check
** @return 1 if it's a valid number, 0 if not
*/
int		is_number(char *str);

/*
** Checks for duplicate values in the stack
** @param stack Stack to check
** @return 1 if duplicates found, 0 if not
*/
int		has_duplicates(t_stack *stack);

/*
** Checks if the stack is already sorted (descending order)
** @param stack Stack to check
** @return 1 if sorted, 0 if not
*/
int		is_sorted(t_stack *stack);

/*
** Converts string to integer with error checking
** @param str String to convert
** @param error Pointer to error flag
** @return The integer value
*/
int		safe_atoi(char *str, int *error);

/*
** Prints error message and exits
** @return Always returns 1
*/
int		exit_with_error(void);

/*
** Finds the maximum value in the stack
** @param stack Stack to search
** @return Maximum value
*/
int		find_max(t_stack *stack);

/*
** Finds the minimum value in the stack
** @param stack Stack to search
** @return Minimum value
*/
int		find_min(t_stack *stack);

/*
** Finds the position of a value in the stack
** @param stack Stack to search
** @param value Value to find
** @return Position of the value (-1 if not found)
*/
int		find_position(t_stack *stack, int value);

/*
** Gets the maximum number of bits needed for radix sort
** @param stack Stack to analyze
** @return Number of bits
*/
int		get_max_bits(t_stack *stack);

/*
** Gets the bit value at a specific position
** @param number Number to check
** @param position Bit position
** @return Bit value (0 or 1)
*/
int		get_bit_at_position(int number, int position);

/*
** Swaps the top two elements of stack A
** @param stack_a Pointer to stack A
*/
void	swap_stack_a(t_stack *stack_a);

/*
** Rotates stack A (top element goes to bottom)
** @param stack_a Pointer to stack A
*/
void	rotate_stack_a(t_stack *stack_a);

/*
** Reverse rotates stack A (bottom element goes to top)
** @param stack_a Pointer to stack A
*/
void	reverse_rotate_stack_a(t_stack *stack_a);

/*
** Pushes the top element from stack B to stack A
** @param stack_a Pointer to stack A
** @param stack_b Pointer to stack B
*/
void	push_to_stack_a(t_stack *stack_a, t_stack *stack_b);

/*
** Pushes the top element from stack A to stack B
** @param stack_a Pointer to stack A
** @param stack_b Pointer to stack B
*/
void	push_to_stack_b(t_stack *stack_a, t_stack *stack_b);

/*
** Rotates the stack until a specific value is at the top
** @param stack Stack to rotate
** @param value Value to bring to top
*/
void	rotate_to_value(t_stack *stack, int value);

/*
** Copies stack values to an array
** @param stack Source stack
** @param array Destination array
*/
void	copy_stack_to_array(t_stack *stack, int *array);

/*
** Creates a sorted array from stack values
** @param stack Stack to sort
** @param sorted_array Array to store sorted values
*/
void	create_sorted_array(t_stack *stack, int *sorted_array);

/*
** Assigns index values to stack elements based on their sorted position
** @param stack Stack to rank
*/
void	rank_stack(t_stack *stack);

/*
** Frees allocated memory for stacks
** @param stack_a Pointer to stack A
** @param stack_b Pointer to stack B
*/
void	free_stacks(t_stack *stack_a, t_stack *stack_b);

/*
** Sorts a stack with 2 elements
** @param stack Stack to sort
*/
void	sort_stack_size_2(t_stack *stack);

/*
** Sorts a stack with 3 elements
** @param stack Stack to sort
*/
void	sort_stack_size_3(t_stack *stack);

/*
** Sorts a stack with up to 5 elements
** @param stack_a Stack A to sort
** @param stack_b Stack B for temporary storage
*/
void	sort_stack_size_5(t_stack *stack_a, t_stack *stack_b);

/*
** Performs radix sort on the stack
** @param stack_a Pointer to stack A
** @param stack_b Pointer to stack B
*/
void	sort_with_radix(t_stack *stack_a, t_stack *stack_b);

/*
** Main sorting function that handles all cases
** @param stack_a Pointer to stack A
** @param stack_b Pointer to stack B
*/
void	sort_stack(t_stack *stack_a, t_stack *stack_b);

/*
** Allocates memory for stacks
** @param ac Number of arguments
** @param stack_a Pointer to stack A
** @param stack_b Pointer to stack B
** @return 1 if successful, 0 if error
*/
int		allocate_stacks(int ac, t_stack **stack_a, t_stack **stack_b);

#endif