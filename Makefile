# Name of the executable
NAME = minishell

# Color definition for print purpose
BROWN=\$(COLOR_PREFIX)[0;33m
BLUE=\$(COLOR_PREFIX)[1;34m
END_COLOR=\$(COLOR_PREFIX)[0m

# Defines the C Compiler
CC := clang

# Path of libraries Libft
LIBFT = $(LIBDIR)/libft
LIBFT_PATH = $(LIBFT)/libft.a

# Dependency libraries
INCDIR := includes
LIBS := -I$(LIBFT) -I$(INCDIR)
LDFLAGS = -L$(LIBFT) -lft

# Flags for compiling
CFLAGS :=  -g3 -DDEBUG=1 -fsanitize=address
# My mac
RLFLAGS = -L/usr/local/opt/readline/lib -I/usr/local/opt/readline/include
# For school mac
# RLFLAGS = -L /Users/$(USER)/.brew/opt/readline/lib -I /Users/$(USER)/.brew/opt/readline/include

# Debug options
DEBUG := -g3 -DDEBUG=1 -fsanitize=address

# Source code directory structure
BINDIR := bin
SRCDIR := src
LOGDIR := log
LIBDIR := libs
TESTDIR := test

# Source code file extension
BUILTIN := builtins_utils.c builtins.c cd.c echo.c env.c exit.c export_utils.c \
			export.c pwd.c unset.c

EXEC := exec_cmd.c fork_utils.c fork_processe.c

EXPAND := expand_dollar_symbol.c expand_wildcards_bonus.c expand_wildcards_utils_bonus.c \
			expand_tilde_symbol.c

PARSING := analysis_utils.c analysis.c files.c free.c get_files.c heredoc.c \
			logic_utils.c logic.c parsing_utils.c parsing.c syntax.c

MAIN := history.c minishell.c prompt.c

FILES := $(addprefix builtin/, $(BUILTIN)) \
		$(addprefix exec/, $(EXEC)) \
		$(addprefix expand/, $(EXPAND)) \
		$(addprefix parsing/, $(PARSING)) \
		$(MAIN)

# %.o file names
NAMES := $(addprefix src/, $(FILES))
OBJECTS := $(NAMES:.c=.o)

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
PURPLE = \033[1;35m
DEFAULT = \033[0m
NORM_ERROR = $(shell (norminette -R  CheckForbiddenSourceHeader  | grep Error! | sed 's/" "/"\n"/g' ))
NORM2_ALL = $(shell (norminette -R  CheckForbiddenSourceHeader  | grep Error | wc -l | xargs))
NORM = 	@if [ $(NORM2_ALL) = "0" ]; then\
			echo "$(GREEN)Norm OK! $(DEFAULT)";\
		else \
			echo "$(RED)Norm Error!$(DEFAULT)\n$(PURPLE)($(NORM_ERROR))$(DEFAULT)";\
		fi

#
# COMPILATION RULES
#

default: all

# Rule for link and generate the binary file
all: $(NAME)

$(NAME): $(LIBFT_PATH) $(OBJECTS)
	@echo -en "$(BROWN) $(END_COLOR)";
	$(CC) $(OBJECTS) $(DEBUG) $(CFLAGS) $(LIBS) $(LDFLAGS) -lreadline -lcurses $(RLFLAGS) -o $@

$(LIBFT_PATH):
	@make -C $(LIBFT)

# Rule for run valgrind tool
valgrind:
	valgrind \
		--track-origins=yes \
		--leak-check=full \
		--leak-resolution=high \
		--log-file=$(LOGDIR)/$@.log \
		$(BINDIR)/$(BINARY)
	@echo -en "\nCheck the log file: $(LOGDIR)/$@.log\n"


# Rule for cleaning the project
clean:
	@echo "Deleting all the binaries files..."
	@make clean -C $(LIBFT)
	@rm -rvf $(OBJECTS)

# Rule for cleaning the project
fclean: clean
	@echo "Deleting the executable files..."
	@make fclean -C $(LIBFT)
	@rm -rvf $(NAME)

re: fclean all

bonus: $(NAME)

norm :
		$(NORM)
		@norminette
