/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:39:19 by adrossig          #+#    #+#             */
/*   Updated: 2022/03/29 12:10:49 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Copies the string src to dest, but only up to size - 1.
 *
 * @param dest The destination string.
 * @param src The source string.
 * @param size The size of the destination string.
 *
 * @returns The length of the source string.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	tmp;

	tmp = 0;
	if (!src)
		return (MY_OK);
	if (size > 0)
	{
		while (*(src + tmp) && tmp + 1 < size)
		{
			*(dest + tmp) = *(src + tmp);
			tmp++;
		}
		*(dest + tmp) = '\0';
	}
	return (ft_strlen(src));
}
