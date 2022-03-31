/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 10:55:55 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 13:27:07 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

typedef void	(*t_free)(void **);
typedef void	*(*t_dup)(void *);

typedef struct s_vector
{
	void	**a;
	size_t	max;
	size_t	len;
	t_free	free;
	t_dup	dup;
}	t_vector;

int			ft_vector_free(t_vector *pv);
t_vector	ft_vector_new(size_t max, t_free tfree);
int			ft_vector_init(t_vector *v, size_t max, t_free tfree,
				t_dup tdup);
int			ft_vector_extend(t_vector *v);
int			ft_vector_add(t_vector *v, void *item);
int			ft_vector_set(t_vector *v, size_t i, void *item);
int			ft_vector_insert(t_vector *v, size_t i, void *item);
int			ft_vector_delete(t_vector *v, size_t i);
int			ft_vector_cpy(t_vector *w, t_vector *v);

#endif
