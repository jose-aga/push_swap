/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_movs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-aga <jose-aga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:57:12 by jose-aga          #+#    #+#             */
/*   Updated: 2023/02/07 09:15:29 by jose-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Rotate: The top element of the stack goes to bottom
*/
void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_last_element(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

/*
	ft_ra: Send the top element from 'a' to the bottom
	Print "ra" in the terminal
*/
void	ft_ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

/*
	ft_rb: Send the top element from 'b' to the bottom
	Print "rb" in the terminal
*/
void	ft_rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

/*
	ft_rr: Send the top element of both stacks to the bottom
	Print "rr" in the terminal
*/
void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
