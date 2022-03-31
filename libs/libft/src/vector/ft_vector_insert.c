/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 11:17:35 by adrossig          #+#    #+#             */
/*   Updated: 2022/03/29 12:10:49 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Inserts an item into a vector at a specified index.
 *
 * @param vector The vector to insert into.
 * @param i The index to insert at.
 * @param item The item to insert.
 *
 * @returns OK if the item was inserted, KO if the vector was NULL 
 * or the index was out of bounds.
 */
int	ft_vector_insert(t_vector *vector, size_t i, void *item)
{
	if (!vector || !item)
		return (KO);
	if (i < 0)
		i = vector->len - 1;
	else if (i > vector->len)
		i = vector->len;
	if (vector->len + 1 > vector->max)
		ft_vector_extend(vector);
	vector->a[i] = item;
	vector->len++;
	return (MY_OK);
}

/**
 * Adds an item to the end of a vector.
 *
 * @param vector The vector to add the item to.
 * @param item The item to add to the vector.
 *
 * @returns OK if the item was added successfully, KO otherwise.
 */
int	ft_vector_add(t_vector *vector, void *item)
{
	if (!vector || !item)
		return (KO);
	if (vector->len + 1 > vector->max)
		ft_vector_extend(vector);
	vector->a[vector->len++] = item;
	return (MY_OK);
}

/**
 * Sets the item at index i in the vector.
 *
 * @param vector The vector to set the item in.
 * @param i The index of the item to set.
 * @param item The item to set.
 *
 * @returns OK if the item was set, KO otherwise.
 */
int	ft_vector_set(t_vector *vector, size_t i, void *item)
{
	if (!vector || !item || i >= vector->len)
		return (KO);
	if (i < 0)
		i = vector->len - 1;
	vector->free(&(vector->a[i]));
	vector->a[i] = item;
	return (MY_OK);
}
