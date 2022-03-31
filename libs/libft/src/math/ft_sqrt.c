/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:35:42 by adrossig          #+#    #+#             */
/*   Updated: 2022/03/29 12:10:49 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Computes the square root of a number.
 *
 * @param nbr The number to compute the square root of.
 *
 * @returns The square root of the number.
 */
double	ft_sqrt(double nbr)
{
	int	i;

	i = 1;
	if (nbr == 0)
		return (MY_OK);
	while ((i * i) < nbr)
		i++;
	if ((i * i) == nbr)
		return (i);
	else
		return (MY_OK);
}
