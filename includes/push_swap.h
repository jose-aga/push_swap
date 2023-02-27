/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-aga <jose-aga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:33:48 by jose-aga          #+#    #+#             */
/*   Updated: 2023/02/27 12:35:56 by jose-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				number;
	int				idx;
	int				position;
	int				dest_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/*
	Validate data input
*/

int					is_number(char c);
int					is_sign(char c);
int					plus_number(const char *s1, const char *s2);
int					input_is_ok(char **av);
int					nbr_abs(int nbr);

/*
	Auxiliary functions
*/

long int			ft_atoi(const char *str);
void				ft_putstr(char *str);

/*
	Stacks operations
*/

t_stack				*stack_new(int s);
t_stack				*fill_stack(int ac, char **av);
int					stack_is_sorted(t_stack *stack);
void				stack_add_bottom(t_stack **stack, t_stack *new);
int					get_stack_size(t_stack *stack);
t_stack				*get_last_element(t_stack *stack);
t_stack				*get_penultimate_element(t_stack *stack);
void				assign_idx(t_stack *stack_a, int stack_size);

/*
	Errors
*/

void				error_free_exit(t_stack **stack_a, t_stack **stack_b);
void				free_stack(t_stack **stack);

/*
	Index
*/

int					find_high_idx(t_stack *stack);

/*
	Sort operations
*/

void				swap(t_stack *stack);
void				ft_sa(t_stack **stack_a);
void				ft_sb(t_stack **stack_b);
void				ft_ss(t_stack **stack_a, t_stack **stack_b);

void				rotate(t_stack **stack);
void				ft_ra(t_stack **stack_a);
void				ft_rb(t_stack **stack_b);
void				ft_rr(t_stack **stack_a, t_stack **stack_b);

void				rev_rotate(t_stack **stack);
void				ft_rra(t_stack **stack_a);
void				ft_rrb(t_stack **stack_b);
void				ft_rrr(t_stack **stack_a, t_stack **stack_b);

/*
	Sort methods
*/

void				small_sort(t_stack **stack);
void				sort(t_stack **stack_a, t_stack **stack_b);
void				ft_pa(t_stack **stack_a, t_stack **stack_b);
void				ft_pb(t_stack **stack_a, t_stack **stack_b);
void				move(t_stack **a, t_stack **b, int cost_a, int cost_b);
void				send(t_stack **src, t_stack **des);

/*
	Position
*/

void				get_pos(t_stack **stack);
int					get_low_idx_pos(t_stack **stack);
int					get_tget(t_stack **a, int b_idx, int t_idx, int dest_pos);
void				get_target_pos(t_stack **a, t_stack **b);

/*
	Cost of moving
*/

void				how_much(t_stack **stack_a, t_stack **stack_b);
void				find_chipest_move(t_stack **stack_a, t_stack **stack_b);

#endif