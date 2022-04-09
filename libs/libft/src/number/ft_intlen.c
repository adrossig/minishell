/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:43:16 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 12:44:54 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Calcule la longueur d'un entier n,
** de type int.
** =========
** #1 : un entier n.
** =========
** Retourne le nombre de chiffre dans n.
*/

size_t	ft_intlen(int n)
{
	int	i;

	i = 1;
	n /= 10;
	while (n)
		i++;
	return (i);
}
