/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:01:21 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/12 00:04:10 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Joins two strings together.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @param n The number of characters to join.
 *
 * @returns The joined string.
 */
char	*ft_strnjoin(char *s1, char *s2, int n)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	str = malloc(sizeof(char) * ft_strlen(s1) + n + 1);
	if (!s1 || !(str))
	{
		free(s1);
		return (NULL);
	}
	while (*(s1 + ++i))
		*(str + i) = *(s1 + i);
	while (j < n && *(s2 + j))
	{
		*(str + i + j) = *(s2 + j);
		j++;
	}
	*(str + i + j) = '\0';
	free(s1);
	return (str);
}
