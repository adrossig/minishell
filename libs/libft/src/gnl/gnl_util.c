/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 09:46:23 by arossign          #+#    #+#             */
/*   Updated: 2022/03/14 09:49:43 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*sub_str(char *s, size_t len)
{
	unsigned int	i;
	unsigned int	s_len;
	char			*str;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < len)
		len = s_len;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = s[i];
	str[i] = 0;
	return (str);
}
