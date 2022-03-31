/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_putstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:42:36 by adrossig          #+#    #+#             */
/*   Updated: 2022/03/29 12:10:49 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Prints the contents of an array.
 *
 * @param array The array to print.
 *
 * @returns None
 */
int	ft_array_putstr(t_array *array)
{
	int	i;

	i = 0;
	while (i < array->size)
	{
		i++;
	}
	ft_putchar('\n');
	return (MY_OK);
}
