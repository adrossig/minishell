/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 10:40:08 by adrossig          #+#    #+#             */
/*   Updated: 2021/11/03 18:06:59 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include "libft.h"

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}	t_list;

int		ft_lstsize(t_list *lst);
void	ft_lst_putstr(t_list *elem);
void	ft_lst_putendl(t_list *elem);
void	ft_lst_putstr_fd(t_list *elem, int fd);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lst_addlast(t_list **head, t_list *last);
size_t	ft_lstlenght(t_list *list);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstappend(t_list *head, t_list *last);
t_list	*ft_lstnnew(void const *content, size_t content_size);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
			void (*del)(void *));
void	ft_lst_free(t_list **list, void (*content_free)(void **));
void	ft_lst_free_if(t_list **plst, int (*cond)(void *, void *),
			void *data, void (*c_free)(void **));
void	ft_lst_freeif(t_list **plst, int (*cond)(void *),
			void (*c_free)(void **));

#endif
