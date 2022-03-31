/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bintohexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:46:52 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:06:03 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Converts a binary number to hexadecimal.
 *
 * @param binary The binary number to convert.
 *
 * @returns The hexadecimal representation of the binary number.
 */
int	ft_bintohexa(int binary)
{
	int	hexadecimal;
	int	i;

	hexadecimal = 0;
	i = 1;
	while (binary != 0)
	{
		hexadecimal = hexadecimal + binary % 10 * i;
		i = i * 2;
		binary = binary / 10;
	}
	return (hexadecimal);
}
