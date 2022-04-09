/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:55:48 by adrossig          #+#    #+#             */
/*   Updated: 2022/03/29 12:10:49 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Checks if a character is in a given character set.
 *
 * @param str The character to check.
 * @param charset The character set to check against.
 *
 * @returns 1 if the character is in the character set, 0 otherwise.
 */
int	ft_charset(char str, char *charset)
{
	int	i;

	i = 0;
	while (*(charset + i))
	{
		if (str == *(charset + i))
			return (1);
		i++;
	}
	return (MY_OK);
}
