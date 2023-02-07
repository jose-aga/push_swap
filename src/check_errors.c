/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-aga <jose-aga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:48:24 by jose-aga          #+#    #+#             */
/*   Updated: 2023/02/02 09:54:02 by jose-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
	Check if an input value is a valid number.
*/
static int	argv_is_nbr(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && is_number(av[i]))
		i++;
	if (av[i] != '\0' && !is_number(av[i]))
		return (0);
	return (1);
}

/*
	Check duplicates
*/
static int	check_twins(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && plus_number(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
	Input value is zero (0)
*/
static int	nbr_is_zero(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

/*
	Check if the argument input is consider as valid data
	Argument must be all digits, whitout duplicates
*/
int	input_is_ok(char **av)
{
	int	i;
	int	zeros;

	zeros = 0;
	i = 1;
	while (av[i])
	{
		if (!argv_is_nbr(av[i]))
			return (0);
		zeros += nbr_is_zero(av[i]);
		i++;
	}
	if (zeros > 1)
		return (0);
	if (check_twins(av))
		return (0);
	return (1);
}
