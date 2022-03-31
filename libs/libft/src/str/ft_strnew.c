/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:41:36 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/12 00:03:41 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Allocates a new string of size size and initializes it to '\0'.
 *
 * @param size The size of the string to allocate.
 *
 * @returns A pointer to the newly allocated string.
 */
char	*ft_strnew(size_t size)
{
	char	*locma;

	locma = (char *)malloc(sizeof(char) * (size + 1));
	if (!(locma))
		return (NULL);
	ft_bzero(locma, size);
	return (locma);
}
