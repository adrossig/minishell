/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:32:43 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:47:22 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Prints an unsigned integer in a given base.
 *
 * @param n The unsigned integer to print.
 * @param base The base to print the integer in.
 * @param ch The character to use for the digits.
 * @param fd The file descriptor to print to.
 *
 * @returns None
 */
void	ft_putuint_base_fd(uintmax_t n, int base, int ch, int fd)
{
	if (base < 0 || fd < 0)
		return ;
	if (n >= (unsigned)base)
	{
		ft_putuint_base_fd(n / base, base, ch, fd);
		ft_putuint_base_fd(n % base, base, ch, fd);
	}
	else
		ft_putchar_fd((n + '0') * (base <= 10 || n < 10)
			+ (n % 10 + ch) * (n >= 10), fd);
}
