/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 10:45:44 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:01:15 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Converts an integer to a string using the given base.
 *
 * @param n The integer to convert.
 * @param base The base to use.
 *
 * @returns The string representation of the integer.
 */
char	*ft_itoa_base(unsigned int n, const char *base)
{
	unsigned int	div;
	unsigned int	len;
	char			*res;

	div = n;
	if (n == 0)
		len = 1;
	else
		len = 0;
	while (div != 0 && len++)
		div = div / (unsigned int)ft_strlen((char *)base);
	res = calloc((len + 1), sizeof(char));
	if (!(res))
		return (NULL);
	res[0] = '0';
	while (n != 0 && len--)
	{
		res[len] = base[(n % (unsigned int)ft_strlen((char *)base))];
		n = n / (unsigned int)ft_strlen((char *)base);
	}
	return (res);
}
