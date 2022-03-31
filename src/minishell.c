/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorrean <ltorrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:25:47 by arossign          #+#    #+#             */
/*   Updated: 2022/03/30 21:23:51 by ltorrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	update_shlvl(char **envp)
{
	int		i;
	int		shlvl;
	char	*hol;
	char	*shlvl_str;

	i = 0;
	while (envp && envp[i])
	{
		envp[i] = ft_strdup(envp[i]);
		i++;
	}
	shlvl = ft_atoi(ft_getenv("SHLVL=", envp));
	hol = ft_itoa(shlvl + 1);
	shlvl_str = ft_strjoin("SHLVL=", hol);
	free (hol);
	update_envp(shlvl_str, envp);
	free(shlvl_str);
}

char	*utils(char *prompt, char **envp)
{
	char	*line;

	if (ft_getenv("HOME=", envp) && ft_getenv("PWD=", envp)
		&& !ft_strcmp(ft_getenv("PWD=", envp), ft_getenv("HOME=", envp)))
		line = readline_config(RL_S RED RL_E MINISHELL_HOME RL_S RES RL_E);
	else
		line = readline_config(prompt);
	return (line);
}

int	main(int ac, char **av, char **envp)
{
	update_shlvl(envp);
	g_vars.exit_shell = 257;
	display_prompt(RL_S GRN RL_E MINISHELL RL_S RES RL_E, envp);
	(void)ac;
	(void)av;
	return (0);
}
