/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:38:33 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:58:46 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Iterates over a string and calls a function on each character.
 *
 * @param s The string to iterate over.
 * @param f The function to call on each character.
 *
 * @returns None
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (f && s)
	{
		while (*(s + i))
		{
			f(i, &s[i]);
			i++;
		}
	}
}
