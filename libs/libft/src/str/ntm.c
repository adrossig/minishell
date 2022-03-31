/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ntm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorrean <ltorrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:52:12 by ltorrean          #+#    #+#             */
/*   Updated: 2022/03/30 17:52:13 by ltorrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	check_quotes(char *line)
{
	int	i;

	i = 0;
	if (line && line[i] == '\'')
	{
		i++;
		while (line[i] && line[i] != '\'')
			i++;
	}
	else if (line && line[i] == '"')
	{
		i++;
		while (line[i] && line[i] != '"')
			i++;
	}
	return (i);
}
