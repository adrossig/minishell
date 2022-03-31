/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:41:50 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/12 00:04:15 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Computes the length of a string.
 *
 * @param s The string to compute the length of.
 * @param c The character to stop counting at.
 *
 * @returns The length of the string.
 */
size_t	ft_strnlen(const char *s, char c)
{
	int		i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
		i++;
	return (i);
}
