/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:38:49 by adrossig          #+#    #+#             */
/*   Updated: 2022/03/30 14:35:07 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Joins two strings together.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 *
 * @returns The joined string.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	len;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s = (char *)malloc((size_t)len);
	if (s == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (++i >= 0 && s1 && s1[i])
		s[i] = s1[i];
	while (s2 && s2[j])
		s[i++] = s2[j++];
	s[i] = '\0';
	return (s);
}
