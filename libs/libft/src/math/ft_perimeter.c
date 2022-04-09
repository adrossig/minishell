/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perimeter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 12:07:59 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:38:14 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Computes the perimeter of a rectangle.
 *
 * @param width The width of the rectangle.
 * @param height The height of the rectangle.
 *
 * @returns The perimeter of the rectangle.
 */
int	ft_perimeter(int width, int height)
{
	int	result;

	result = ((2 * height) + (2 * width));
	return (result);
}
