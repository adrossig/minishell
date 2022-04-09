/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uncrypt_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 11:20:42 by adrossig          #+#    #+#             */
/*   Updated: 2022/03/29 12:09:49 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Decrypts a string.
 *
 * @param decalage The amount to shift the string.
 * @param str The string to decrypt.
 *
 * @returns None
 */
void	ft_uncrypt_str(int decalage, char *str)
{
	ft_crypt_str(decalage * -1, str);
}
