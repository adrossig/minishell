/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:47:33 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/12 00:06:03 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 '.
 * Computes the length of a string. '.
 * '.
 * @param s1 The string to compute the length of. '.
 * '.
 * @returns The length of the string. '.
 */
char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	j = ft_strlen(s1) - 1;
	while (*(s1 + i) && ft_strchr(set, *(s1 + i)))
		i++;
	if (!*(s1 + i))
		return (ft_strdup(""));
	while (*(s1 + j) && ft_strchr(set, *(s1 + j)))
		j--;
	return (ft_substr(s1, i, j - i + 1));
}
