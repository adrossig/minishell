/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:40:20 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/12 00:01:24 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Concatenates two strings.
 *
 * @param dest The destination string.
 * @param src The source string.
 * @param n The number of characters to copy from the source string.
 *
 * @returns The destination string.
 */
char	*ft_strncat(char *dest, const char *src, size_t n)
{
	unsigned int	i;
	size_t			size;

	i = 0;
	size = ft_strlen(dest);
	while (i < n && *(src + i))
	{
		*(dest + size + i) = *(src + i);
		++i;
	}
	*(dest + size + i) = '\0';
	return (dest);
}
