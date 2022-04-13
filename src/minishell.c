/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:25:47 by arossign          #+#    #+#             */
/*   Updated: 2022/04/13 12:12:15 by arossign         ###   ########.fr       */
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
	char	buff[PATH_MAX];
	char	s[PATH_MAX];

	s[0] = 0;
	ft_strcpy(s, ARW RL_S SYA RL_E);
	if (ft_getenv("HOME=", envp) && ft_getenv("PWD=", envp)
		&& !ft_strcmp(ft_getenv("PWD=", envp), ft_getenv("HOME=", envp)))
		line = readline_config(ARW RL_S RED RL_E MINISHELL_HOME RL_S RES RL_E);
	else
	{
		if (getcwd(buff, sizeof(buff)) == NULL)
			line = readline_config(prompt);
		else
		{
			ft_strcat(s, ft_strrchr(buff, '/') + 1);
			ft_strcat(s, " \1\e[0m\2");
			line = readline_config(s);
		}
	}
	return (line);
}

void	write_start_minishell(void)
{
	ft_putstr_fd(RL_S "\e[0;31m" RL_E"\n"
		" ███▄ ▄███▓ ██▓ ███▄    █  ██▓  ██████  ██░ ██ ▓█████  ██▓     ██▓    "
		"\n"
		"▓██▒▀█▀ ██▒▓██▒ ██ ▀█   █ ▓██▒▒██    ▒ ▓██░ ██▒▓█   ▀ ▓██▒    ▓██▒    "
		"\n"
		"▓██    ▓██░▒██▒▓██  ▀█ ██▒▒██▒░ ▓██▄   ▒██▀▀██░▒███   ▒██░    ▒██░    "
		"\n"
		"▒██    ▒██ ░██░▓██▒  ▐▌██▒░██░  ▒   ██▒░▓█ ░██ ▒▓█  ▄ ▒██░    ▒██░    "
		"\n"
		"▒██▒   ░██▒░██░▒██░   ▓██░░██░▒██████▒▒░▓█▒░██▓░▒████▒░██████▒░██████▒"
		"\n"
		"░ ▒░   ░  ░░▓  ░ ▒░   ▒ ▒ ░▓  ▒ ▒▓▒ ▒ ░ ▒ ░░▒░▒░░ ▒░ ░░ ▒░▓  ░░ ▒░▓  ░"
		"\n"
		"░  ░      ░ ▒ ░░ ░░   ░ ▒░ ▒ ░░ ░▒  ░ ░ ▒ ░▒░ ░ ░ ░  ░░ ░ ▒  ░░ ░ ▒  ░"
		"\n"
		"░      ░    ▒ ░   ░   ░ ░  ▒ ░░  ░  ░   ░  ░░ ░   ░     ░ ░     ░ ░   "
		"\n"
		"       ░    ░           ░  ░        ░   ░  ░  ░   ░  ░    ░  ░    ░  ░"
		"\n"
		RL_S RES RL_E, 2);
}


void* my_malloc(size_t size, const char *file, int line, const char *func)
{
    void *p = malloc(size);
    printf ("Allocated = %s, %i, %s, %p[%li]\n", file, line, func, p, size);
    /*Link List functionality goes in here*/
    return p;
}

int	main(int ac, char **av, char **envp)
{
	t_exit	exit_;

	write_start_minishell();
	update_shlvl(envp);
	exit_.exit_shell = 257;
	if (exit_.exit_code < 0)
		exit_.exit_code = 0;
	display_prompt(ARW RL_S SYA RL_E MINISHELL RL_S RES RL_E, envp, &exit_);
	(void)ac;
	(void)av;
	return (0);
}
