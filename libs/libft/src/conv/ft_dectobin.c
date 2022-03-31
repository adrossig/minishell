/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectobin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:12:50 by adrossig          #+#    #+#             */
/*   Updated: 2022/03/29 12:10:49 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Converts a decimal number to binary.
 *
 * @param decimal The decimal number to convert.
 *
 * @returns The binary representation of the decimal number.
 */
long long	ft_dectobin(int decimal)
{
	long long	binary;
	int			i;

	i = 1;
	binary = 0;
	while (decimal != 0)
	{
		decimal /= 2;
		binary += decimal % 2 * i;
		i *= 10;
	}
	return (binary);
}

long long	ft_dectobin_recursive(int decimal)
{
	if (decimal == 0)
		return (MY_OK);
	else
		return (decimal % 2 + 10 * ft_dectobin_recursive(decimal / 2));
}
