/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:39:02 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:59:03 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Concatenates two strings.
 *
 * @param dest The destination string.
 * @param src The source string.
 * @param size The size of the destination string.
 *
 * @returns The length of the concatenated string.
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*(dest + i) != '\0' && i < size)
		i++;
	while (*(src + j) && i + j + 1 < size)
	{
		*(dest + i + j) = *(src + j);
		j++;
	}
	if (i != size)
		*(dest + i + j) = '\0';
	return (i + ft_strlen(src));
}
