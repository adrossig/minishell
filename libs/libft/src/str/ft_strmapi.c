/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:40:06 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/12 00:01:10 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Applies a function to each character of a string and returns a new string.
 *
 * @param s The string to map.
 * @param f The function to apply to each character.
 *
 * @returns A new string with the results of the function.
 */
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	size;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	str = ft_strnew(size);
	while (size--)
		*(str + size) = f(size, *(s + size));
	return (str);
}
