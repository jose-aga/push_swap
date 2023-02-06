/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_movs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-aga <jose-aga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:25:58 by jose-aga          #+#    #+#             */
/*   Updated: 2023/02/06 12:46:28 by jose-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Swap two top elements of the "a" stack.
*/
void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->number;
	stack->number = stack->next->number;
	stack->next->number = tmp;
	tmp = stack->idx;
	stack->idx = stack->next->idx;
	stack->next->idx = tmp;
}

/*
	Swap the two top elements from stack 'a' and prints "sa" in terminal
*/
void	ft_sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr_fd("sa\n", 1);
}

/*
	Swap the two top elements from stack 'b' and prints "sb" in terminal
*/
void	ft_sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putstr_fd("sb\n", 1);
}

/*
	Swap the two top elements from stack 'a' & 'b' 
	and prints "ss" in terminal
*/
void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr_fd("ss\n", 1);
}
