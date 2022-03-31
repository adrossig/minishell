/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexatooctal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:02:55 by adrossig          #+#    #+#             */
/*   Updated: 2022/03/29 12:10:49 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Converts a hexadecimal string to an octal number.
 *
 * @param hex The hexadecimal string to convert.
 *
 * @returns The octal number.
 */
long long	ft_hexatooctal(char *hex)
{
	int	temp;
	int	result;

	if (!hex)
		return (MY_OK);
	temp = ft_todec(hex, 16);
	result = ft_dectooctal(temp);
	return (result);
}
