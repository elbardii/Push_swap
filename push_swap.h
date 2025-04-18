/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 06:02:43 by isel-bar          #+#    #+#             */
/*   Updated: 2025/04/18 11:49:02 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*array;
	int	top;
}		t_stack;

/* Stack initialization and validation functions */
int		init_stack(int ac, char **av, t_stack *stack_a, t_stack *stack_b);
int		is_number(char *str);
int		has_duplicates(t_stack *stack);
int		is_sorted(t_stack *stack);
int		ft_atoi(char *str, int *error);
int		print_error(void);
void	free_stacks(t_stack *stack_a, t_stack *stack_b);

/* Stack operations */
void	swap_a(t_stack *stack_a);
void	rotate_a(t_stack *stack_a);
void	reverse_rotate_a(t_stack *stack_a);
void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_a, t_stack *stack_b);

/* Helper functions */
int		find_max(t_stack *stack);
int		find_min(t_stack *stack);
int		find_position(t_stack *stack, int value);
void	rotate_to_value(t_stack *stack, int value);
void	fill_array(t_stack *stack, int *array);
void	create_sorted_array(t_stack *stack_a, int *sorted);
void	assign_ranks(t_stack *stack);

/* Bit manipulation for radix sort */
int		get_max_bits(t_stack *stack);
int		get_bit_at_position(int num, int position);

/* Sorting algorithms */
void	sort_two(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	sort(t_stack *stack_a, t_stack *stack_b);

#endif