/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 10:54:31 by adrossig          #+#    #+#             */
/*   Updated: 2022/03/29 12:10:49 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Initializes a vector structure.
 *
 * @param vector The vector to initialize.
 * @param max The maximum number of elements in the vector.
 * @param free The function to call to free the elements in the vector.
 * @param dup The function to call to duplicate the elements in the vector.
 *
 * @returns OK if the vector was successfully initialized, KO otherwise.
 */
int	ft_vector_init(t_vector *vector, size_t max, t_free free, t_dup dup)
{
	if (!vector || !free || !max)
		return (KO);
	vector->a = ft_memalloc((max + 1) * sizeof(void *));
	if (!(vector->a))
		return (KO);
	vector->max = max;
	vector->len = 0;
	vector->free = free;
	vector->dup = dup;
	while (max-- > 0)
		vector->a[max] = NULL;
	return (MY_OK);
}

/**
 * Extends the capacity of a vector.
 *
 * @param vector The vector to extend.
 *
 * @returns OK if the vector was extended, KO otherwise.
 */
int	ft_vector_extend(t_vector *vector)
{
	size_t	i;
	void	**anew;

	if (!vector)
		return (KO);
	anew = ft_memalloc((2 * vector->max + 1) * sizeof(void *));
	if (!(anew))
		return (KO);
	vector->max *= 2;
	i = 0;
	while (i < vector->len)
	{
		*(anew + i) = vector->a[i];
		i++;
	}
	while (i <= vector->max)
		*(anew + i++) = NULL;
	ft_memdel((void **)&(vector->a));
	vector->a = anew;
	return (MY_OK);
}

int	ft_vector_cpy(t_vector *w, t_vector *vector)
{
	size_t	i;

	if (!vector || !vector->a)
		return (KO);
	if (ft_vector_init(w, vector->max, vector->free, vector->dup) == KO)
		return (KO);
	i = 0;
	while (i < vector->len)
	{
		w->a[i] = vector->dup(vector->a[i]);
		i++;
	}
	while (i < vector->max)
		w->a[i++] = NULL;
	return (MY_OK);
}
