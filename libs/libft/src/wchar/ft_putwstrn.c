/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstrn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:01:34 by arossign          #+#    #+#             */
/*   Updated: 2022/02/12 00:09:54 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Writes a wide character to a file descriptor.
 *
 * @param wchar The wide character to write.
 * @param fd The file descriptor to write to.
 *
 * @returns None
 */
void	ft_putnwstr_fd(wint_t *wstr, int n, int fd)
{
	int	i;

	if (!wstr || n < 1 || fd < 0)
		return ;
	i = 0;
	while (i < n && wstr[i])
		ft_putwchar_fd(wstr[i++], fd);
}
