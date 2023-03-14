/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-aga <jose-aga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:31:04 by jose-aga          #+#    #+#             */
/*   Updated: 2023/03/14 09:29:04 by jose-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
	Check if a provided stack is sorted
*/
int	stack_is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/*
	Choose the best sorting method depending on the number
	of input values
*/
static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !stack_is_sorted(*stack_a))
		ft_sa(stack_a);
	else if (stack_size == 3)
		small_sort(stack_a);
	else if (stack_size > 3 && !stack_is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	char	**nbrs;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		nbrs = ft_split(argv[1], ' ');
		if (!nbrs)
			return (free(nbrs), 0);
	}
	else
		nbrs = &argv[1];
	if (!input_is_ok(nbrs))
		error_free_exit(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack(argc, nbrs);
	stack_size = get_stack_size(stack_a);
	assign_idx(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
