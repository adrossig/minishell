/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayadd_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:41:27 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:28:13 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Adds a value to an array at a given position.
 *
 * @param array The array to add the value to.
 * @param position The position in the array to add the value to.
 * @param value The value to add to the array.
 *
 * @returns SUCCESS if the value was added successfully,
 * POSITION_INIT if the position was already initialized,
 * or INVALID_POSITION if the position is invalid.
 */
int	ft_arrayadd_value(t_array *array, int position, int value)
{
	if (position >= 0 && position < array->size)
	{
		if (array->array[position] == 0)
		{
			array->array[position] = value;
			return (SUCCESS);
		}
		else
			return (POSITION_INIT);
	}
	return (INVALID_POSITION);
}
