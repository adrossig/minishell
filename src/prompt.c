/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:25:54 by arossign          #+#    #+#             */
/*   Updated: 2022/04/12 09:23:27 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	sig_handel(int signal)
{
	if ((signal == SIGINT || signal == SIGQUIT) && g_sig_indice)
	{
		printf("\r");
		rl_on_new_line();
		rl_redisplay();
	}
	if (signal == SIGINT && g_sig_indice && g_sig_indice != -1)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (signal == SIGINT && g_sig_indice == -1)
	{
		g_sig_indice = 0;
		printf("\n");
		exit(1);
	}
}

void	check_empty_line(void)
{
	char			cursor[13];
	int				i;
	int				y;
	struct termios	old;
	struct termios	new;

	ft_bzero(cursor, 13);
	if (tcgetattr(STDIN_FILENO, &old))
		return (perror("tcgetattr"));
	new = old;
	new.c_lflag &= ~(ICANON | ECHO);
	if (tcsetattr(STDIN_FILENO, TCSANOW | TCSAFLUSH, &new))
		return (perror("tcsetattr"));
	i = 0;
	write(0, "\1\033[6n\2", 6);
	new.c_cc[VTIME] = 0;
	read(0, cursor, 13);
	while (cursor[i] != ';' && i < 8)
		i++;
	y = ft_atoi(&cursor[i + 1]);
	if (tcsetattr(STDIN_FILENO, TCSANOW | TCSAFLUSH, &old))
		return (perror("tcsetattr"));
	if (y > 1)
		ft_putstr_fd("", STDOUT_FILENO);
}

int	empty_prompt(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (!str[i])
		return (1);
	return (0);
}

char	*readline_config(char *prompt)
{
	char			*line;
	struct termios	old;
	struct termios	new;

	if (tcgetattr(STDIN_FILENO, &old))
		perror("tcgetattr");
	new = old;
	new.c_lflag &= ~(ECHOCTL);
	if (tcsetattr(STDIN_FILENO, TCSANOW | TCSAFLUSH, &new))
		perror("tcsetattr");
	line = readline(prompt);
	if (tcsetattr(STDIN_FILENO, TCSANOW | TCSAFLUSH, &old))
		perror("tcsetattr");
	return (line);
}

void	display_prompt(char	*prompt, char **envp, t_exit *exit_)
{
	char	*line;

	signal(SIGINT, sig_handel);
	signal(SIGQUIT, sig_handel);
	init_add_history(envp);
	while (1)
	{
		g_sig_indice = 1;
		line = utils(prompt, envp);
		g_sig_indice = 0;
		if (!line)
			exit_minishell_ctrl_d(envp, exit_);
		if (*line)
			add_to_history(line, envp);
		if (empty_prompt(line))
			;
		else if (valid_syntax(line))
			parse_logic(line, envp, exit_);
		else
			exit_->exit_code = 258;
		free(line);
		if (exit_->exit_shell != 257)
			exit(exit_->exit_shell);
	}
}
