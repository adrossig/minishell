/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:26:39 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:06:27 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Converts a number to a string in the specified base.
 *
 * @param number The number to convert.
 * @param base The base to convert to.
 *
 * @returns The string representation of the number.
 */
static	char	*ft_base(unsigned long long number, int base, int count,
	char *str)
{
	while (number != 0)
	{
		if ((number % base) < 10)
			str[count - 1] = (number % base) + 48;
		else
			str[count - 1] = (number % base) + 55;
		number /= base;
		count--;
	}
	return (str);
}

char	*ft_utl_base(unsigned long long number, int base)
{
	unsigned long long	temp;
	int					count;
	char				*str;

	temp = number;
	str = 0;
	count = 0;
	if (number == 0)
		return (ft_strdup("0"));
	while (number != 0)
	{
		number /= base;
		count++;
	}
	str = malloc(count + 1);
	if (!str)
		return (0);
	str[count] = '\0';
	str = ft_base(temp, base, count, str);
	return (str);
}
