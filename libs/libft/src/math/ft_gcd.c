/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gcd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:34:16 by adrossig          #+#    #+#             */
/*   Updated: 2022/03/29 12:10:49 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Computes the greatest common divisor of two numbers.
 *
 * @param nbr1 The first number.
 * @param nbr2 The second number.
 *
 * @returns The greatest common divisor of the two numbers.
 */
int	ft_gcd(int nbr1, int nbr2)
{
	if (nbr1 < 0)
		nbr1 = -nbr1;
	if (nbr2 < 0)
		nbr2 = -nbr2;
	while (nbr1 != nbr2)
	{
		if (nbr1 > nbr2)
			nbr1 -= nbr2;
		else
			nbr2 -= nbr1;
	}
	return (MY_OK);
}
