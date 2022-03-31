/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:02:01 by arossign          #+#    #+#             */
/*   Updated: 2022/02/14 14:42:12 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Computes the length of a wide character.
 *
 * @param wch The wide character.
 *
 * @returns The length of the wide character.
 */
int	ft_wchar_len(wint_t wch)
{
	if (wch < 0x0 || wch > 0x7FFFFFFF)
		return (-1);
	else if (wch < 0x80)
		return (1);
	else if (wch < 0x800)
		return (2);
	else if (wch < 0x10000)
		return (3);
	else if (wch < 0x200000)
		return (4);
	else if (wch < 0x4000000)
		return (5);
	else
		return (6);
}
