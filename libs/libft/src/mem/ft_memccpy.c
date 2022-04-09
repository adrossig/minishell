/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:30:35 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:41:03 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Copies the first n characters from the string str2 to str1.
 *
 * @param str1 The destination string.
 * @param str2 The source string.
 * @param c The character to copy.
 * @param n The number of characters to copy.
 *
 * @returns A pointer to the first character in str1.
 */
void	*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*src;

	dest = (unsigned char *)str1;
	src = (unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		*(dest + i) = *(src + i);
		if (*(dest + i) == (unsigned char)c)
			return ((unsigned char *)(dest + (i + 1)));
		i++;
	}
	return (NULL);
}
