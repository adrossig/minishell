/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:02:50 by arossign          #+#    #+#             */
/*   Updated: 2022/02/11 23:13:50 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Converts a string to an unsigned integer.
 *
 * @param s The string to convert.
 *
 * @returns The converted unsigned integer.
 */
uint64_t	ft_atoui(const char *s)
{
	uint64_t	n;

	n = 0;
	if (*s == '-')
		return (0);
	while (s && *s >= '0' && *s <= '9' && n < UINT32_MAX)
		n = (n * 10) + (*s++ - '0');
	if (n >= UINT32_MAX)
		return (UINT32_MAX);
	return (n);
}
