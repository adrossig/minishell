/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:02:58 by arossign          #+#    #+#             */
/*   Updated: 2022/02/11 23:13:56 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	atoi_power(int base, unsigned int power)
{
	unsigned int	i;
	int				nb;

	if (power == 0)
		return (1);
	i = 1;
	nb = base;
	while (i++ < power)
		base = base * nb;
	return (base);
}

/**
 * Converts a string to an integer.
 *
 * @param str The string to convert.
 * @param base The base of the string.
 *
 * @returns The integer representation of the string.
 */
int	ft_atoi_base(const char *str, int base)
{
	int	nbr;
	int	len;
	int	i;

	len = ft_strlen(str);
	i = len;
	nbr = 0;
	while (--i > 0 || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A'
			&& str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr = nbr + atoi_power(base, len - (i + 1)) * (str[i] - '0');
		else if (str[i] >= 'a' && str[i] <= 'z')
			nbr = nbr + atoi_power(base, len - (i + 1)) * (str[i] - 'a' + 10);
		else if (str[i] >= 'A' && str[i] <= 'Z')
			nbr = nbr + atoi_power(base, len - (i + 1)) * (str[i] - 'A' + 10);
	}
	return (nbr);
}
