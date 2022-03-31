/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:40:34 by adrossig          #+#    #+#             */
/*   Updated: 2022/03/29 12:10:49 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Compares two strings for equality.
 *
 * @param str1 The first string.
 * @param str2 The second string.
 * @param i The number of characters to compare.
 *
 * @returns 0 if the strings are equal, otherwise returns the difference between
 * the first differing characters.
 */
int	ft_strncmp(const char *str1, const char *str2, size_t i)
{
	unsigned int	j;

	j = 0;
	if (i == 0)
		return (MY_OK);
	while ((*(str1 + j) == *(str2 + j)) && *(str2 + j) && (--i))
		++j;
	return ((unsigned char)*(str1 + j) - (unsigned char)*(str2 + j));
}
