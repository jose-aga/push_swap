/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-aga <jose-aga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:18:00 by jose-aga          #+#    #+#             */
/*   Updated: 2023/02/02 09:33:26 by jose-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/*
	Create NODE
*/
t_stack* createnewnode(int number)
{
	t_stack *new = NULL;
	new = (t_stack*)malloc(sizeof(t_stack));
	if (new != NULL)
	{
		new->number = number;
		new->next = NULL;
	}
	return (new);
}

int	inserthead(t_stack **head, int number)
{
	t_stack*	new = NULL;

	new = createnewnode(number);
	if (new != NULL)
	{
		new->next = *head;
		*head = new;
		return (1);
	}
	return (0);
}
