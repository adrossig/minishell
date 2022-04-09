/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:31:09 by adrossig          #+#    #+#             */
/*   Updated: 2022/03/29 12:10:49 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Compares two strings.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @param n The number of characters to compare.
 *
 * @returns 0 if the strings are equal, -1 if s1 is less than s2, 1 if s1 is
 * greater than s2.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (MY_OK);
	while (i < (n - 1)
		&& *((unsigned char *)(s1 + i)) == *((unsigned char *)(s2 + i)))
		i++;
	return (*((unsigned char *)(s1 + i)) - *((unsigned char *)(s2 + i)));
}
