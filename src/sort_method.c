/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_method.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-aga <jose-aga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:39:28 by jose-aga          #+#    #+#             */
/*   Updated: 2023/02/07 11:45:43 by jose-aga         ###   ########.fr       */
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

/*
    Sort a stack with 3 elements
*/
void    small_sort(t_stack **stack)
{
    int high;

    if (stack_is_sorted(*stack))
        return;
    high = find_high_idx(*stack);
    if ((*stack)->idx == high)
        ft_ra(stack);
    else if ((*stack)->next->idx == high)
        ft_rra(stack);
    if ((*stack)->idx > (*stack)->next->idx)
        ft_sa(stack);
}

/*
    Move all elements from 'a' to 'b' except 3 last ones.
    Smaller values first, then larger values,
*/
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

/*
    
*/
static void    put_low_at_top(t_stack **stack_a)
{
    int lowest_pos;
    int stack_size;

    stack_size = get_stack_size(*stack_a);
    lowest_pos = get_low_idx_pos(stack_a);
    if (lowest_pos > stack_size / 2)
    {
        while (lowest_pos < stack_size)
        {
            ft_rra(stack_a);
            lowest_pos++;
        }
    }
    else
    {
        while (lowest_pos > 0)
        {
            ft_ra(stack_a);
            lowest_pos--;
        }
    }
}

void    sort(t_stack **stack_a, t_stack **stack_b)
{
    move_all_less_3(stack_a, stack_b);
    small_sort(stack_a);
    while (*stack_b)
    {
        get_target_pos(stack_a, stack_b);
        how_much(stack_a, stack_b);
        find_chipest_move(stack_a, stack_b);
    }
    if (!stack_is_sorted(*stack_a))
        put_low_at_top(stack_a);
}
