/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_lenght.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:15:45 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 22:55:46 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Computes the length of an array.
 *
 * @param array The array whose length is to be computed.
 *
 * @returns The length of the array.
 */
size_t	ft_array_lenght(void **array)
{
	ssize_t	lenght;

	lenght = -1;
	while (*(array + lenght))
		++lenght;
	return (lenght);
}
