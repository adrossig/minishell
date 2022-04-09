/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lcm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:30:07 by adrossig          #+#    #+#             */
/*   Updated: 2022/03/29 12:10:49 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Computes the least common multiple of two numbers.
 *
 * @param nbr1 The first number.
 * @param nbr2 The second number.
 *
 * @returns The least common multiple of the two numbers.
 */
int	ft_lcm(int nbr1, int nbr2)
{
	int	min;

	if (nbr1 > nbr2)
		min = nbr1;
	else
		min = nbr2;
	while (1)
	{
		if (min % nbr1 == 0 && min % nbr2 == 0)
		{
			break ;
		}
		++min;
	}
	return (MY_OK);
}
