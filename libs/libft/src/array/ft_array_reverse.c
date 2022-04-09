/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_reverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:52:01 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 22:55:56 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Reverses the order of the elements in an array.
 *
 * @param array The array to reverse.
 *
 * @returns None
 */
int	ft_array_reverse(t_array *array)
{
	int	i;

	i = 0;
	while (i < array->size / 2)
	{
		ft_array_swap(array, i, array->size - i - 1);
		i++;
	}
	return (SUCCESS);
}
