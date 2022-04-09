/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_todec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 14:00:56 by adrossig          #+#    #+#             */
/*   Updated: 2022/03/29 12:10:49 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	value(char c)
{
	if (c >= '0' && c <= '9')
		return ((int)c - '0');
	else
		return ((int)c - 'A' + 10);
}

/**
 * Converts a string to a decimal number.
 *
 * @param str The string to convert.
 * @param base The base of the string.
 *
 * @returns The converted number.
 */
int	ft_todec(char *str, int base)
{
	int	lenght;
	int	power;
	int	num;
	int	i;

	if (!str)
		return (MY_OK);
	lenght = ft_strlen(str);
	power = 1;
	num = 0;
	i = lenght - 1;
	while (i >= 0)
	{
		num += value(*(str + i)) * power;
		power = power * base;
		i--;
	}
	return (num);
}
