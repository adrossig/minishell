/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:37:22 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/12 00:05:51 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Reverses a string.
 *
 * @param str The string to reverse.
 *
 * @returns The reversed string.
 */
char	*ft_strrev(char *str)
{
	int		i;
	int		length;
	char	buff;

	i = 0;
	length = ft_strlen(str);
	while (length - 1 > i)
	{
		buff = *(str + i);
		*(str + i) = *(str + length - 1);
		*(str + length - 1) = buff;
		length--;
		i++;
	}
	return (str);
}
