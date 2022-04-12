/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:02:55 by arossign          #+#    #+#             */
/*   Updated: 2022/04/12 09:57:45 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	unclosed_quote(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		i += check_quotes(&line[i]) + 1;
		if (!line[i - 1])
			return (1);
	}
	return (0);
}

int	unclosed_parenthesis(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		i += check_quotes(&line[i]);
		i += check_parenthesis(&line[i]);
		if (!line[i++])
			return (1);
		if (line[i] == ')')
			return (1);
	}
	return (0);
}

int	check_valid_parenthesis_2(char *line)
{
	int	i;

	i = 1;
	while (line[i] == ' ')
		i++;
	if (line[i] == ')' || line[0] == ')')
		return (1);
	while (line[i] && line[i] != ')')
	{
		i += check_quotes(&line[i]);
		i++;
	}
	while (line[i] && (line[i] == ')' || line[i] == ' '))
		i++;
	if (line[i])
		return (1);
	return (0);
}

int	check_valid_parenthesis(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '(')
		i++;
	while (line[i])
	{
		i += check_quotes(&line[i]);
		if (line[i] == '(')
			return (1);
		i++;
	}
	if (check_valid_parenthesis_2(line))
		return (1);
	return (0);
}

int	check_special_char(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		i += check_quotes(&line[i]);
		if (line[i] == ';' || line[i] == '\\')
			return (1);
		i++;
	}
	return (0);
}
