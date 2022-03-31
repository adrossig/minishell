/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:41:03 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/12 00:03:02 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Copies the first n characters of the string s2 to s1.
 *
 * @param s1 The destination string.
 * @param s2 The source string.
 * @param n The number of characters to copy.
 *
 * @returns None
 */
char	*ft_strndup(const char *s, size_t n)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * (n + 1));
	if (!(s2))
		return (NULL);
	while (*(s + i) && i < n)
	{
		*(s2 + i) = *(s + i);
		i++;
	}
	*(s2 + i) = '\0';
	return (s2);
}
