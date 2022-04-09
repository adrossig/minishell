/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:30:50 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:42:55 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Searches for the first occurrence of the character c in the string str.
 *
 * @param str The string to search.
 * @param c The character to search for.
 * @param n The number of characters to search.
 *
 * @returns The first occurrence of the character c in the string str.
 */
void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			j;
	unsigned char	*dest;

	j = 0;
	dest = (unsigned char *)str;
	while (n-- > 0)
	{
		if (*(dest + j) == (unsigned char)c)
			return (dest + j);
		j++;
	}
	return (NULL);
}
