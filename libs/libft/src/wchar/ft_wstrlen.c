/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:01:28 by arossign          #+#    #+#             */
/*   Updated: 2022/02/12 00:10:20 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Computes the length of a wide character string.
 *
 * @param wstr The wide character string.
 *
 * @returns The length of the string.
 */
size_t	ft_wstrlenz(wint_t *wstr)
{
	if (!wstr || *wstr == L'\0')
		return (0);
	return (ft_wchar_len(*wstr) + ft_wstrlenz(wstr + 1));
}
