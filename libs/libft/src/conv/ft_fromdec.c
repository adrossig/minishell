/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fromdec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 14:19:25 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:02:56 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	value(int number)
{
	if (number >= 0 && number <= 9)
		return ((char)(number + '0'));
	else
		return ((char)(number - 10 + 'A'));
}

static void	strev(char *str)
{
	int		lenght;
	int		i;
	char	temp;

	lenght = strlen(str);
	i = 0;
	while (i < lenght / 2)
	{
		temp = *(str + i);
		*(str + i) = *(str + lenght + i - 1);
		*(str + lenght - i - 1) = temp;
		i++;
	}
}

/**
 * Converts a decimal number to a string in a given base.
 *
 * @param number The number to convert.
 * @param base The base to convert to.
 *
 * @returns The string representation of the number in the given base.
 */
char	*ft_fromdec(int number, int base, char *result)
{
	int	index;

	index = 0;
	while (number > 0)
	{
		*(result + index++) = value(number % base);
		number /= base;
	}
	*(result + index) = '\0';
	strev(result);
	return (result);
}
