/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 11:02:59 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/12 00:07:07 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Converts all characters in a string to lowercase.
 *
 * @param str The string to convert.
 *
 * @returns The converted string.
 */
char	*ft_tolower_str(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		*(str + i) = ft_tolower(*(str + i));
		i++;
	}
	return (str);
}
