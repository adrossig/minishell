/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 10:48:01 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:32:44 by arossign         ###   ########.fr       */
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
void	ft_lst_putstr(t_list *elem)
{
	if (!elem)
		return ;
	else
		ft_putstr((char *)elem->content);
}
