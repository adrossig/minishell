/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:32:05 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:45:23 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Sets the first n bytes of the memory pointed to by str to the specified value.
 *
 * @param str The memory to set.
 * @param i The value to set the memory to.
 * @param n The number of bytes to set.
 *
 * @returns The memory that was set.
 */
void	*ft_memset(void *str, int i, size_t n)
{
	size_t	j;

	j = 0;
	while (j < n)
	{
		*(((unsigned char *)str) + j) = (unsigned char)i;
		j++;
	}
	return (str);
}
