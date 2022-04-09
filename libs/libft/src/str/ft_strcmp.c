/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:36:46 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:51:07 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Compares two strings.
 *
 * @param str1 The first string.
 * @param str2 The second string.
 *
 * @returns 0 if the strings are equal, -1 if str1 is less than str2,
 * 1 if str1 is greater than str2.
**/
int	ft_strcmp(const char *str1, const char *str2)
{
	unsigned int	i;

	i = 0;
	while (*(str1 + i) == *(str2 + i) && *(str1 + i))
		i++;
	return (((unsigned char)*(str1 + i)) - ((unsigned char)*(str2 + i)));
}
