/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-aga <jose-aga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 08:46:29 by jose-aga          #+#    #+#             */
/*   Updated: 2023/02/07 08:02:33 by jose-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Check if the character is a number
*/
int	is_number(char c)
{
	return (c >= '0' && c <= '9');
}

/*
	Return the abosolute value of a number
*/
int	nbr_abs(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

/*
	Check if the character is '+' or '-'
*/
int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

/*
	Compare two strings to check if a number have a '+'. Example 19 = +19	
*/
int	plus_number(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
