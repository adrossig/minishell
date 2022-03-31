/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorrean <ltorrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:26:56 by arossign          #+#    #+#             */
/*   Updated: 2022/03/30 21:26:24 by ltorrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// Standard Library
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <curses.h>
# include <term.h>
# include <termios.h>

// Local Library
# include "../libs/libft/includes/libft.h"

// struct
typedef struct s_collect
{
	char	*slash_cmd;
	char	**paths;
	char	**cmd;
}	t_collect;

typedef struct s_global
{
	int	sig_indice;
	int	exit_shell;
	int	exit_code;
}	t_global;

t_global	g_vars;

// Local define
# define APPEND_MODE 1
# define TRUNC_MODE 0

# define REDIR_TOK "minishell: syntax error near unexpected token `redirection'"
# define LINE_TOKEN "minishell: syntax error near unexpected token `newline'"
# define PARENTH_TOKEN "minishell: syntax error near unexpected token `()'"
# define ERR_S_CHAR "minishell: syntax error: forbidden special character"
# define MULTI_LINE "minishell: syntax error multiple line not allowed"
# define PIPE_TOKEN "minishell: syntax error near unexpected token `|'"
# define AND_TOKEN "minishell: syntax error near unexpected token `&'"
# define ERR_LOGIC "minishell: syntax error: duplicated logic symbols"
# define ERR_PARENTH "minishell: syntax error: unclosed parenthesis"
# define ERR_EXIT_ARG "minishell: exit: numeric argument required"
# define ERR_QUOTES "minishell: syntax error: unclosed quotes"
# define ERR_DIR "minishell: unable to read current directory"
# define ERR_EXIT_NUM "minishell: exit: too many arguments"
# define UNSET_ARG "minishell: unset: invalid identifier"
# define EXP_ARG "	 export: invalid identifier"
# define ERR_USAGE ": usage: . filename [arguments]"
# define ERR_ARGS ": No such file or directory"
# define CMD_ERROR ": command not found"
# define ERR_PERM ": Permission denied"
# define ERR_ISDIR ": is a directory"
# define RL_S "\1"
# define RL_E "\2"
# define GRN "\e[0;32m"
# define RED "\e[0;31m"
# define RES "\e[0m"
# define MINISHELL "mminishell_$ "
# define MINISHELL_HOME "~ "

//Functions
//Builtin functions:
char	*ft_getenv(char *var, char **envp);
void	ft_pwd(char **args);
void	ft_echo(char **args);
void	check_plus(char **var);
void	print_envp(char **envp);
void	ft_cd(char **args, char **envp);
void	exit_minishell_ctrl_d(char **envp);
void	ft_env(char **args, char **envp);
void	ft_exit(char **args, char **envp);
void	ft_unset(char **args, char **envp);
void	ft_export(char **args, char **envp);
int		update_envp(char *var, char **envp);
int		check_num_arg(char c, char *error_msg);
int		check_builtin(char *cmd, int stdin_dup, int fd, char **envp);

//Exec functions:
void	exit_builtin(int r_builtint);
void	execute_cmd(char *cmd, char **envp);
void	get_exit_code(int pid, int *status);
void	fork_processes(t_list *cmds, char **envp);
void	fork_child_2(char *cmd, int stdin_dup, char **envp);
void	fork_child_1(char *cmd, int stdin_dup, int *fd, char **envp);
int		fork_here_doc(char *cmd, int stdin_dup);

//Expand functions:
int		quoted_wildcard(char *name);
int		get_length_char_wildcard(char *str);
int		examin_entry_name(char *file, char *name);
char	*expand_wildcards(char *name);
char	*get_wildcards_expressions(char *line);
char	*expand_dollar_symbol(char *line, char **envp);

//Parsing functions:
char	*file_io_name(char *str, int aut);
char	*here_doc(char *limiter, int stdin_no);
char	*get_last_cmd(char *cmd, int *logic_opp);
void	free_2d(char **strs);
void	remove_quotes_1d(char *str);
void	remove_quotes_2d(char **strs);
void	parse_input(char *line, char **envp);
void	parse_logic(char *cmds, char **envp);
void	get_here_doc_input(char *cmd, int stdin_dup);
void	to_space(char *str, size_t start, size_t len);
void	exit_error(t_collect *var, char *short_cmd, char *msg, int exit_code);
int		valid_syntax(char *line);
int		check_quotes(char *line);
int		unclosed_quote(char *line);
int		get_length_char(char *str);
int		check_priorities(char *cmd);
int		check_parenthesis(char *cmd);
int		check_special_char(char *line);
int		check_general_syntax(char *str);
int		check_single_quotes(char *line);
int		unclosed_parenthesis(char *line);
int		check_valid_parenthesis(char *line);
int		check_redirection_syntax(char *str);
int		get_io_files(char *cmd, int stdin_no);
int		open_output_file(char *outfile, int mode);
int		open_input_file(char *infile, int stdin_no);

//Main functions:
char	*readline_config(char *prompt);
char	*utils(char *prompt, char **envp);
void	check_empty_line(void);
void	init_add_history(char **envp);
void	add_to_history(char *line, char **envp);
void	display_prompt(char	*prompt, char **envp);

//Fix readline:
void	rl_replace_line(const char *text, int clear_undo);

#endif
