/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:20:44 by adrossig          #+#    #+#             */
/*   Updated: 2022/03/29 12:10:49 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Checks if a number is prime.
 *
 * @param nbr The number to check.
 *
 * @returns 1 if the number is prime, 0 otherwise.
 */
int	ft_is_prime(int nbr)
{
	int	i;

	i = 2;
	if (nbr < 0)
		return (MY_OK);
	if (nbr == 2)
		return (2);
	while ((nbr % i != 0) && i < nbr)
	{
		i++;
		if (i == nbr)
			return (1);
	}
	return (MY_OK);
}
