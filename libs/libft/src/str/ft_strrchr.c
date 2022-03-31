/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:43:19 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/12 00:05:47 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Finds the last occurrence of a character in a string.
 *
 * @param str The string to search.
 * @param c The character to search for.
 *
 * @returns The last occurrence of the character in the string.
 */
char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*temp;

	temp = (char *)str;
	i = ft_strlen(str);
	while (*(temp + i) != (char)c)
	{
		if (i == 0)
			return (NULL);
		i--;
	}
	return (temp + i);
}
