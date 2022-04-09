/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 16:50:14 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 13:23:20 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICT_H
# define FT_DICT_H

# ifndef MAXELEMENTS
#  define MAXELEMENTS 1000
# endif

typedef struct s_dictionary
{
	void	*elements[MAXELEMENTS];
	int		nbr;
}	t_dictionary;

t_dictionary	ft_init_dict(void);

/*
** create_dict: is a simple constructor for creating a dictionary
*/
t_dictionary	*ft_create_dict(void);

/*
** simple destrcutor function
*/
void			ft_destroy(t_dictionary *dict);

/*
** get_element: returns the element at given index
*/
void			*ft_get_element_index(t_dictionary *dict, int index);

/*
** get_element: returns the element at given label
*/
void			*ft_get_element_label(t_dictionary *dict, char *string);
int				ft_gethash(char *string);

/*
** add_item_index: adds item (void*) to the dictionary at given index (int)
** returns 0 if adding was sucessful otherwise -1
*/
int				ft_add_item_index(t_dictionary *dict, int index, void *item);

/*
**  add_item_label: adds item (void*) to the dictionary at given label
** returns 0 if adding was sucessful otherwise -1
*/
int				ft_add_item_label(t_dictionary *dict, char *label, void *item);

#endif
