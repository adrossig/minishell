/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:38:17 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:58:42 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Applies a function to each character in a string.
 *
 * @param s The string to apply the function to.
 * @param f The function to apply to each character.
 *
 * @returns None
 */
void	ft_striter(char *s, void (*f)(char *))
{
	size_t	i;

	i = 0;
	if (s && f)
	{
		while (*(s + i))
		{
			f(&s[i]);
			i++;
		}
	}
}
