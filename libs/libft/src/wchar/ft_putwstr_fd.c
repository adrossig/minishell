/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:01:39 by arossign          #+#    #+#             */
/*   Updated: 2022/02/12 00:09:46 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Writes a wide character to a file descriptor.
 *
 * @param c The wide character to write.
 * @param fd The file descriptor to write to.
 *
 * @returns None
 */
void	ft_putwstr_fd(wchar_t *str, int fd)
{
	while (*str)
	{
		ft_putwchar_fd(*str, fd);
		str++;
	}
}
