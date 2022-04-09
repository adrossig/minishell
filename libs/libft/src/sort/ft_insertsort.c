/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:20:17 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:47:36 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Insertion sort algorithm.
 *
 * @param a The array to sort.
 * @param b The size of the array.
 *
 * @returns None
 */
void	ft_insertsort(int *a, int b)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (i < b)
	{
		k = a[i];
		j = i - 1;
		while (j >= 0 && *(a + j) > k)
		{
			*(a + j + 1) = *(a + j);
			j = j - 1;
		}
		*(a + j + 1) = k;
		i++;
	}
}
