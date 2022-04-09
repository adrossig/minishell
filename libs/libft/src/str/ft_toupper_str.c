/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 11:02:40 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/12 00:07:41 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Converts all characters in a string to uppercase.
 *
 * @param str The string to convert.
 *
 * @returns The converted string.
 */
char	*ft_toupper_str(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		*(str + i) = ft_toupper(*(str + i));
		i++;
	}
	return (str);
}
