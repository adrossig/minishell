/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:13:53 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:00:13 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_zeub(long n)
{
	size_t	length;
	int		neg;

	length = 0;
	neg = 0;
	if (n < 0)
	{
		length++;
		neg++;
		n = -n;
	}
	while (n >= 1)
	{
		length++;
		n /= 10;
	}
	return (length);
}

static char	*ft_generate(char *nc, long num, int length, int neg)
{
	if (num != 0)
		nc = malloc(sizeof(char) * (length + 1));
	else
		return (nc = ft_strdup("0"));
	if (!nc)
		return (0);
	neg = 0;
	if (num < 0)
	{
		neg++;
		num = -num;
	}
	nc[length] = '\0';
	while (--length)
	{
		nc[length] = (num % 10) + '0';
		num /= 10;
	}
	if (neg == 1)
		nc[0] = '-';
	else
		nc[0] = (num % 10) + '0';
	return (nc);
}

/**
 * Converts an unsigned integer to a string.
 *
 * @param n The unsigned integer to convert.
 *
 * @returns A string representation of the unsigned integer.
 */
char	*ft_uitoa(unsigned int n)
{
	int		length;
	char	*nc;
	long	num;
	int		neg;

	num = n;
	length = ft_zeub(num);
	nc = 0;
	neg = 0;
	nc = ft_generate(nc, num, length, neg);
	if (!nc)
		return (0);
	return (nc);
}
