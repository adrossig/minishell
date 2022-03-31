/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_surface.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 12:08:20 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:40:26 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Computes the surface area of a rectangular prism.
 *
 * @param width The width of the rectangular prism.
 * @param height The height of the rectangular prism.
 *
 * @returns The surface area of the rectangular prism.
 */
int	ft_surface(int width, int height)
{
	int	result;

	result = width * height;
	return (result);
}
