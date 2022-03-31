/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:39:49 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/12 00:00:34 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Applies a function to every character in a string.
 *
 * @param s The string to apply the function to.
 * @param f The function to apply.
 *
 * @returns A new string with the function applied to every character.
 */
char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*s2;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!(s2))
		return (NULL);
	while (*(s + i) != '\0')
	{
		*(s2 + i) = f(*(s + i));
		i++;
	}
	*(s2 + i) = '\0';
	return (s2);
}
