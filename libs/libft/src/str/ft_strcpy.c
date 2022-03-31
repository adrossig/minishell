/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:37:02 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:51:14 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Copies the contents of one string to another.
 *
 * @param dest The destination string.
 * @param src The source string.
 *
 * @returns The destination string.
 */
char	*ft_strcpy(char *dest, const char *src)
{
	unsigned int	i;

	i = 0;
	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		++i;
	}
	*(dest + i) = '\0';
	return (dest);
}
