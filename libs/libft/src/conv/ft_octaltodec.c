/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octaltodec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 11:28:16 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:00:23 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Converts an octal number to a decimal number.
 *
 * @param octal The octal number to convert.
 *
 * @returns The decimal number.
 */
long long	ft_octaltodec(int octal)
{
	int	decimal;
	int	i;

	decimal = 0;
	i = 0;
	while (octal != 0)
	{
		decimal += (octal % 10) * ft_power(8, i);
		++i;
		octal /= 10;
	}
	i = 1;
	return (decimal);
}
