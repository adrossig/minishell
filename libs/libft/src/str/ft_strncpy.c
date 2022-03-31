/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:40:47 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/12 00:02:57 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Copies the first i characters of src to dest.
 *
 * @param dest The destination string.
 * @param src The source string.
 * @param i The number of characters to copy.
 *
 * @returns The destination string.
 */
char	*ft_strncpy(char *dest, const char *src, size_t i)
{
	unsigned int	j;

	j = 0;
	while ((*(src + j) != '\0') && j < i)
	{
		*(dest + j) = *(src + j);
		j++;
	}
	while (j < i)
	{
		*(dest + j) = '\0';
		j++;
	}
	return (dest);
}
