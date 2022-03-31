/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 11:29:29 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:00:05 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Converts a number to an hexadecimal.
 *
 * @param base The base of the string.
 * @param nbr The number to convert.
 * @param lenght The length of the number to convert.
 *
 * @returns The converted number.
 */
char	*ft_tohexa(char *base, unsigned long nbr, unsigned long lenght)
{
	char			*locma;
	long			i;
	unsigned long	result;
	unsigned long	divisor;

	i = 0;
	result = 0;
	divisor = 1;
	if (!base)
		return (NULL);
	locma = malloc(sizeof(char) * 33);
	if (!(locma))
		return (NULL);
	while ((nbr / divisor) >= lenght)
		divisor *= lenght;
	while (divisor > 0)
	{
		result = (nbr / divisor) % lenght;
		*(locma + i++) = *(base + result);
		divisor /= lenght;
	}
	*(locma + i) = 0;
	return (locma);
}
