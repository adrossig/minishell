/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:05:27 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:05:54 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Converts a decimal number to a hexadecimal number.
 *
 * @param decimal The decimal number to convert.
 *
 * @returns The hexadecimal number.
 */
char	*ft_dectohexa(int decimal)
{
	int		remainder;
	int		i;
	char	hexadecimal[3];

	remainder = 0;
	i = 0;
	while (decimal > 0 && i >= 0)
	{
		remainder = decimal % 16;
		if (remainder < 10)
			*(hexadecimal + i) = (char)remainder + 48;
		else
			*(hexadecimal + i) = (char)remainder + 55;
		decimal /= 16;
		i++;
	}
	*(hexadecimal + i) = '\0';
	return (ft_strrev(hexadecimal));
}
