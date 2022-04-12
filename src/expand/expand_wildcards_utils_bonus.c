/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcards_utils_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorrean <ltorrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:22:54 by arossign          #+#    #+#             */
/*   Updated: 2022/04/11 16:46:31 by ltorrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	wildcards_exeption(char *entry_d_name, char *name)
{
	if (ft_strnstr(name, ".*.", ft_strlen(name)))
		return (1);
	return ((ft_strncmp(entry_d_name, ".", 1) || !ft_strcmp(name, ".*")));
}

int	quoted_wildcard(char *name)
{
	int	i;

	i = 0;
	while (name[i])
	{
		if (name[i] == '\'')
		{
			while (name[i++] && name[i] != '\'')
			{
				if (name[i] == '*')
					return (1);
			}
		}
		if (name[i] == '"')
		{
			while (name[i++] && name[i] != '"')
			{
				if (name[i] == '*')
					return (1);
			}
		}
		i++;
	}
	return (0);
}

int	get_length_char_wildcard(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '<' && str[i] != '|'
		&& str[i] != '>')
	{
		i += check_quotes(&str[i]);
		i++;
	}
	return (i);
}

void	find_match(char *name, char *file, int *i, int *j)
{
	int	hol;

	if (name[*j] == '*')
	{
		while (name[*j] == '*')
			(*j)++;
		hol = *j;
		while (file[*i] && name[*j] != '*')
		{
			*j = hol;
			while (file[*i] && (file[*i] != name[*j]
					|| file[*i] == file[(*i) + 1]))
				(*i)++;
			while (file[*i] && name[*j] && file[*i] == name[*j] && ++(*i))
				(*j)++;
		}
	}
}

int	examin_entry_name(char *file, char *name)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file[i] && name[j])
	{
		while (file[i] == name[j] && name[j] != '*' && ++i)
			j++;
		find_match(name, file, &i, &j);
		if (file[i] != name[j] && name[j] != '*')
			return (1);
	}
	if ((file[i] || name[j]) && name[j] != '*')
		return (1);
	return (0);
}
