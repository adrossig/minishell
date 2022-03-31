/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gethash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:45:53 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:27:39 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Computes the hash value of a string.
 *
 * @param string The string to hash.
 *
 * @returns The hash value of the string.
 */
int	ft_gethash(char *string)
{
	unsigned int	hash;
	int				counter;

	counter = 0;
	while (*(string + counter) != '\0')
	{
		hash = *(string + counter) + (hash << 6) + (hash << 16) - hash;
		counter++;
	}
	return (hash % MAXELEMENTS);
}
