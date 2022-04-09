/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:30:08 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:40:58 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Allocates memory for an array of n elements.
 *
 * @param n The number of elements in the array.
 *
 * @returns A pointer to the allocated memory.
 */
void	*ft_memalloc(size_t size)
{
	void	*memory;

	memory = malloc(sizeof(memory) * size);
	if (!(memory))
		return (NULL);
	ft_bzero(memory, size);
	return (memory);
}
