/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectooctal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:46:11 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:05:50 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Converts a decimal number to octal.
 *
 * @param decimal The decimal number to convert.
 *
 * @returns The octal representation of the decimal number.
 */
int	ft_dectooctal(int decimal)
{
	int	octal;
	int	i;

	octal = 0;
	i = 1;
	while (decimal != 0)
	{
		octal = (decimal % 8 * i) + octal;
		decimal /= 8;
		i *= 10;
	}
	return (octal);
}
