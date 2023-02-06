/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_movs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-aga <jose-aga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:10:23 by jose-aga          #+#    #+#             */
/*   Updated: 2023/02/06 22:39:34 by jose-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Rev_rotate: Send the bottom element to the top of the stack
*/
void	rev_rotate(t_stack **stack)
{
	t_stack *tmp;
	t_stack *tail;
	t_stack *penultimate;

	tail = get_last_element(*stack);
	penultimate = get_penultimate_element(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	penultimate->next = NULL;
}

/*
	ft_rra: Send the last element from stack 'a' to the top
*/
void	ft_rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	ft_putchar("rra\n");
}

/*
	ft_rrb: Send the last element from stack 'b' to the top
*/
void	ft_rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	ft_putchar("rrb\n");
}

/*
	ft_rrr: Send the last element from both stacks to the top
*/
void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putchar("rrr\n");
}
