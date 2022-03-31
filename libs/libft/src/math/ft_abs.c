/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 10:56:33 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:36:40 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Computes the absolute value of a long long integer.
 *
 * @param n The long long integer to compute the absolute value of.
 *
 * @returns The absolute value of the input.
 */
long long	ft_abs(long long n)
{
	long long	nb;

	if (n >= 0)
		nb = n;
	else
		nb = -n;
	return (nb);
}
