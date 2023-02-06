/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-aga <jose-aga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:26:15 by jose-aga          #+#    #+#             */
/*   Updated: 2023/02/06 14:09:36 by jose-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Fill stack "a" with a valid integer range
*/
t_stack	*fill_stack(int ac, char **av)
{
	t_stack		*stack_a;
	long int	nbr;
	int			i;

	stack_a = NULL;
	nbr = 0;
	i = 1;
	while (i < ac)
	{
		nbr = ft_atoi(av[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			null_error(&stack_a, NULL);
		if (i == 1)
			stack_a = stack_new((int)nbr);
		else
			stack_add_bottom(&stack_a, stack_new((int)nbr));
		i++;
	}
	return (stack_a);
}

/*
	Create stack elements
*/
t_stack *stack_new(int s)
{
	t_stack *new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->number = s;
	new->idx = 0;
	new->position = -1;
	new->dest_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

/*
	Assign an index to the values of the stack
*/
void	assign_idx(t_stack *stack_a, int stack_size)
{
	t_stack *ptr;
	t_stack *maxvalue;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = -2147483648;
		maxvalue = NULL;
		while (ptr)
		{
			if (ptr->number == -2147483648 && ptr->idx == 0)
				ptr->idx = 1;
			if (ptr->number > value && ptr->idx == 0)
			{
				value = ptr->number;
				maxvalue = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (maxvalue != NULL)
			maxvalue->idx = stack_size;
	}
}
