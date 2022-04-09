/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:01:55 by arossign          #+#    #+#             */
/*   Updated: 2022/02/12 00:09:41 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Prints a wide character to the standard output.
 *
 * @param c The wide character to print.
 *
 * @returns None
 */
void	ft_putwchar(wchar_t c)
{
	ft_putwchar_fd(c, 1);
}
