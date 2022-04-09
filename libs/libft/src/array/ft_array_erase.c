/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_erase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:46:55 by adrossig          #+#    #+#             */
/*   Updated: 2022/03/29 12:10:49 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Erases the contents of an array.
 *
 * @param array The array to erase.
 *
 * @returns None
 */
int	ft_array_erase(t_array *array)
{
	int	i;

	i = 0;
	while (i < array->size)
	{
		array->array[i] = 0;
		i++;
	}
	return (MY_OK);
}
