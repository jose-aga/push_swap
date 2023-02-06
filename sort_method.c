/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_method.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-aga <jose-aga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:39:28 by jose-aga          #+#    #+#             */
/*   Updated: 2023/02/06 17:42:34 by jose-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
    Return the highest index in a stack
*/
int find_high_idx(t_stack *stack)
{
    int idx;
    
    idx = stack->idx;
    while (stack)
    {
        if (stack->idx > idx)
            idx = stack->idx;
        stack = stack->next;
    }
    return (idx);
}

void    small_sort(t_stack **stack)
{
    int high;

    if (stack_is_sorted(*stack))
        return;
    high = find_high_idx(*stack)
    if ((*stack)->idx == high)
        ft_ra(stack);
    else if ((*stack)->next->idx == high)
        ft_rra(stack);
    if ((*stack)->idx > (*stack)->next->idx)
        ft_sa(stack);
}

void    move_all_less_3(t_stack **stack_a, t_stack **stack_b)
{
    int stack_size;
    int moved;
    int i;

    stack_size = get_stack_size(*stack_a);
    moved = 0;
    i = 0;
    while (stack_size > 6 && i < stack_size && moved < stack_size / 2)
    {
        if ((*stack_a)->idx <= stack_size / 2)
        {
            ft_pb(stack_a, stack_b);
            moved++;
        }
        else
            ft_ra(stack_a);
        i++;
    }
    while (stack_size - moved > 3)
    {
        ft_pb(stack_a, stack_b);
        moved++;
    }
}

void    put_low_at_top(t_stack **stack_a)
{
    int lowest_pos;
    int stack_size;

    stack_size = get_stack_size(*stack_a);
    lowest_pos = get

}