/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorrean <ltorrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:43:49 by adrossig          #+#    #+#             */
/*   Updated: 2022/03/30 17:52:28 by ltorrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Computes the substring of a string.
 *
 * @param s The string to be sliced.
 * @param start The start index of the slice.
 * @param len The length of the slice.
 *
 * @returns The substring of the string.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*ss;
	char	*bb;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	ss = (char *)&s[start];
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	sub = (char *)malloc((size_t)(len + 1));
	if (sub == NULL)
		return (NULL);
	bb = sub;
	while (len-- > 0)
		*bb++ = *ss++;
	*bb = '\0';
	return (sub);
}
