/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:54:51 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:36:29 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Allocates memory for an array of n elements of size size.
 *
 * @param n The number of elements in the array.
 * @param size The size of each element.
 *
 * @returns A pointer to the allocated memory.
 */
void	*ft_calloc(size_t count, size_t size)
{
	char	*var;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	var = malloc(sizeof(char) * (count * size));
	if (!(var))
		return (NULL);
	ft_bzero((void *)var, count * size);
	return ((void *)var);
}
