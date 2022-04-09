/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selectsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:35:10 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:47:41 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Sorts an array using the selection sort algorithm.
 *
 * @param a The array to sort.
 * @param b The size of the array.
 *
 * @returns None
 */
void	ft_selectsort(int *a, int b)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < b - 1)
	{
		j = i + 1;
		k = i;
		while (j < b)
		{
			if (*(a + j) < *(a + k))
				k = j;
			ft_swap(&a[k], &a[i]);
			j++;
		}
		i++;
	}
}
