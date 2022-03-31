/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_putstr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 10:51:05 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:32:35 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Prints the content of a list to a file descriptor.
 *
 * @param elem The list to print.
 * @param fd The file descriptor to print to.
 *
 * @returns None
 */
void	ft_lst_putstr_fd(t_list *elem, int fd)
{
	if (!elem)
		return ;
	else
		ft_putstr_fd((char *)elem->content, fd);
}
