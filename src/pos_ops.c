/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-aga <jose-aga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:03:16 by jose-aga          #+#    #+#             */
/*   Updated: 2023/02/07 08:15:03 by jose-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Assign a position to each element of a stack 
	top->bottom.
*/
void	get_pos(t_stack **stack)
{
	t_stack *tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

/*
	Gets current position with low index
*/
int	get_low_idx_pos(t_stack **stack)
{
	t_stack *tmp;
	int		low_idx;
	int		low_pos;

	tmp = *stack;
	low_idx = 2147483647;
	get_pos(stack);
	low_pos = tmp->position;
	while (tmp)
	{
		if (tmp->idx < low_idx)
		{
			low_idx = tmp->idx;
			low_pos = tmp->position;
		}
		tmp = tmp->next;
	}
	return (low_pos);
}

/*
	Best target position in 'a' for the index of the 
	element in 'b'
*/
int	get_target(t_stack **a, int b_idx, int target_idx, int dest_pos)
{
	t_stack *tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->idx > b_idx && tmp_a->idx < target_idx)
		{
			target_idx = tmp_a->idx;
			dest_pos = tmp_a->position;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != 2147483647)
		return (dest_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->idx < target_idx)
		{
			target_idx = tmp_a->idx;
			dest_pos = tmp_a->position;
		}
		tmp_a = tmp_a->next;
	}
	return (dest_pos);
}

/*
	Assign a final position in stack 'a' for each element
*/
void	get_target_pos(t_stack **a, t_stack **b)
{
	t_stack *tmp_b;
	int		dest_pos;

	tmp_b = *b;
	get_pos(a);
	get_pos(b);
	dest_pos = 0;
	while (tmp_b)
	{
		dest_pos = get_target(a, tmp_b->idx, 2147483647, dest_pos);
		tmp_b->dest_pos = dest_pos;
		tmp_b = tmp_b->next;
	}
}