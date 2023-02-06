/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-aga <jose-aga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:04:36 by jose-aga          #+#    #+#             */
/*   Updated: 2023/02/06 17:13:05 by jose-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Move the top element of stack 'src' to the top
	of 'des' stack
*/
void	move(t_stack **src, t_stack **des)
{
	t_stack *tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *des;
	*des = *src;
	*src = tmp;
}

/*
	Move the top element of stack 'b' to the top of stack 'a'
	Prints "pa" in the console
*/
void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	move(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

/*
	Move the top element of stack 'a' to the top of stack 'b'
	Prints "pb" in the console
*/
void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	move(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
