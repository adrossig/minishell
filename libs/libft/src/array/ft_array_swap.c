/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:49:21 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 22:56:01 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Swaps two elements in an array.
 *
 * @param array The array to swap elements in.
 * @param position1 The position of the first element to swap.
 * @param position2 The position of the second element to swap.
 *
 * @returns None
 */
void	ft_array_swap(t_array *array, int position1, int position2)
{
	int	temp;

	temp = array->array[position1];
	array->array[position1] = array->array[position2];
	array->array[position2] = temp;
}
