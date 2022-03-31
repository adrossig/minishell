/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:43:31 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:28:25 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Deletes the value at the specified position in the array.
 *
 * @param array The array to delete the value from.
 * @param value The value to delete.
 *
 * @returns The position of the deleted value, or INVALID_POSITION if the value
 * was not found.
 */
int	ft_arraydel_value(t_array *array, int value)
{
	if (value >= 0 && value < array->size)
	{
		if (array->array[value] != 0)
			array->array[value] = 0;
		else
			return (POSITION_EMPTY);
	}
	return (INVALID_POSITION);
}
