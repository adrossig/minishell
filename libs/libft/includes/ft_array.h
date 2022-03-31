/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:35:41 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 13:24:09 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H

# define ARRAY_ERASED -1
# define SUCCESS 0
# define INVALID_POSITION 1
# define POSITION_INIT 2
# define POSITION_NOT_INIT 3
# define POSITION_EMPTY 4
# define ARRAY_FULL 5

# include <stdlib.h>

typedef struct s_array
{
	int		*array;
	int		size;
	char	*data;
}	t_array;

void			ft_arraylst_free(t_array *arraylist);
void			ft_array_swap(t_array *array, int position1, int position2);
size_t			ft_array_lenght(void **array);
int				ft_array_erase(t_array *array);
int				ft_array_reverse(t_array *array);
int				ft_arraydel_value(t_array *array, int value);
int				ft_arrayadd_value(t_array *array, int position, int value);

#endif
