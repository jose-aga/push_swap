/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-aga <jose-aga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:22:51 by jose-aga          #+#    #+#             */
/*   Updated: 2023/02/13 13:05:03 by jose-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	How_much the cost of moving each element from 'b' to the
	correct position in 'a'

	cost_b -> number of movements to get each element from top of the 'b'
	cost_a -> number of movements to get the right position in 'a'
*/
void	how_much(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = get_stack_size(tmp_a);
	size_b = get_stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->position;
		if (tmp_b->position > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->position) * -1;
		tmp_b->cost_a = tmp_b->dest_pos;
		if (tmp_b->dest_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->dest_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

/*
	Find chipest move to put in destination position 'a' an 
	element in stack 'b'
*/
void	find_chipest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = 2147483647;
	while (tmp)
	{
		if (nbr_abs(tmp->cost_a) + nbr_abs(tmp->cost_b) < nbr_abs(cheapest))
		{
			cheapest = nbr_abs(tmp->cost_b) + nbr_abs(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	move(stack_a, stack_b, cost_a, cost_b);
}
