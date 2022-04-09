/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_putendl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:52:48 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:32:30 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Prints the content of a list.
 *
 * @param elem The list to print.
 *
 * @returns None
 */
void	ft_lst_putendl(t_list *elem)
{
	if (!elem)
		return ;
	else
		ft_putendl((char *)elem->content);
}
