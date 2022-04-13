/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:25:35 by arossign          #+#    #+#             */
/*   Updated: 2022/04/13 12:30:46 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	consecutive_pipe(char *str)
{
	int	i;
	int	cmp_pipe;

	i = 0;
	while (str && str[i])
	{
		cmp_pipe = 0;
		while (str[i] == '>' || str[i] == '<'
			|| str[i] == '|' || str[i] == ' ' || str[i] == '&')
		{
			if (str[i] == '|' || str[i] == '&' || ((str[i] == '>'
						|| str[i] == '<') && !cmp_pipe))
				cmp_pipe++;
			i++;
		}
		if (cmp_pipe > 1)
			return (0);
		i += check_quotes(&str[i]) + 1;
		i += check_parenthesis(&str[i]);
	}
	return (1);
}

int	check_general_syntax(char *str)
{
	str = ft_strtrim(str, " ");
	if (!str[0])
		return (free(str), 2);
	if (str[0] == '|' || !consecutive_pipe(str))
		return (free(str), 0);
	if (str[ft_strlen(str) - 1] == '<'
		|| str[ft_strlen(str) - 1] == '>')
		return (free(str), -1);
	if (str[0] == '&' || str[ft_strlen(str) - 1] == '&')
		return (free(str), 3);
	if (str[ft_strlen(str) - 1] == '|'
		|| str[ft_strlen(str) - 1] == '\\')
		return (free(str), -2);
	return (free(str), 1);
}

int	consecutive_redir_symbol(char *str)
{
	int	i;
	int	cmp_redir;

	i = 0;
	while (str[i])
	{
		cmp_redir = 0;
		while (str[i] == '<' || str[i] == '>' || str[i] == ' ')
		{
			if (str[i] == '<' || str[i] == '>')
				cmp_redir++;
			i++;
		}
		if (cmp_redir > 2)
			return (0);
		i += check_quotes(&str[i]) + 1;
	}
	free(str);
	return (1);
}

int	contradict_redir_symbol(char *str, char symbol_one, char symbol_two)
{
	int	i;
	int	cmp_redir;

	i = 0;
	while (str[i])
	{
		cmp_redir = 0;
		while (str[i] == symbol_one || str[i] == ' ')
		{
			if (str[i] == symbol_one)
				cmp_redir++;
			i++;
		}
		if (str[i] == symbol_two && cmp_redir)
			return (0);
		i += check_quotes(&str[i]) + 1;
	}
	free(str);
	return (1);
}

int	check_redirection_syntax(char *str)
{
	if (!consecutive_redir_symbol(str))
		return (0);
	if (!contradict_redir_symbol(str, '<', '>'))
		return (0);
	if (!contradict_redir_symbol(str, '>', '<'))
		return (0);
	return (1);
}
