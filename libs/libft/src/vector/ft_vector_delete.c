/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 11:15:52 by adrossig          #+#    #+#             */
/*   Updated: 2022/03/29 12:10:49 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Deletes an element from a vector.
 *
 * @param vector The vector to delete an element from.
 * @param i The index of the element to delete.
 *
 * @returns OK if the element was deleted, KO otherwise.
 */
int	ft_vector_delete(t_vector *vector, size_t i)
{
	if (!vector || !vector->a || i >= vector->len)
		return (KO);
	if (i < 0)
		i = vector->len - 1;
	vector->free(&(vector->a[i--]));
	while (++i < vector->len - 1)
		vector->a[i] = vector->a[i + 1];
	vector->a[i] = NULL;
	vector->len--;
	return (MY_OK);
}

/**
 * Frees the memory allocated for a vector.
 *
 * @param vector The vector to free.
 *
 * @returns None
 */
int	ft_vector_free(t_vector *vector)
{
	size_t	i;

	if (!vector || !vector->a)
		return (KO);
	i = 0;
	while (i < vector->len)
		vector->free(&(vector->a[i++]));
	ft_memdel((void **)&(vector->a));
	vector->free = NULL;
	vector->dup = NULL;
	vector->len = 0;
	vector->max = 0;
	return (MY_OK);
}
