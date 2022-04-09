/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:02:08 by arossign          #+#    #+#             */
/*   Updated: 2022/01/11 11:02:09 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putnstr_fd(const char *str, int n, int fd)
{
	int	i;

	if (!str || n < 1 || fd < 0)
		return ;
	i = 0;
	while (i < n && str[i])
		ft_putchar_fd(str[i++], fd);
}

void	ft_putnstr(const char *str, int n)
{
	int	i;

	if (!str || n < 1)
		return ;
	i = 0;
	while (i < n && str[i])
		write(1, &str[i++], 1);
}
