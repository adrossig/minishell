# Name of the executable
NAME = minishell

# Color definition for print purpose
BROWN=\$(COLOR_PREFIX)[0;33m
BLUE=\$(COLOR_PREFIX)[1;34m
END_COLOR=\$(COLOR_PREFIX)[0m

# Defines the C Compiler
CC := gcc

# Path of libraries Libft
LIBFT = $(LIBDIR)/libft
LIBFT_PATH = $(LIBFT)/libft.a

# Dependency libraries
INCDIR := includes
LIBS := -I$(LIBFT) -I$(INCDIR)
LDFLAGS = -L$(LIBFT) -lft

# Flags for compiling
CFLAGS := -Werror -Wall -Wextra -g -g3
RLFLAGS = -L /Users/$(USER)/.brew/opt/readline/lib -I /Users/$(USER)/.brew/opt/readline/include

# Debug options
DEBUG := -g3 -DDEBUG=1

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

EXPAND := expand_dollar_symbol.c expand_wildcards_bonus.c expand_wildcards_utils_bonus.c

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

#
# COMPILATION RULES
#

default: all

# Help message
help:
	@echo "C Project Minishell"
	@echo
	@echo "Target rules:"
	@echo "    all      - Compiles and generates binary file"
	@echo "    tests    - Compiles with cmocka and run tests binary file"
	@echo "    valgrind - Runs binary file using valgrind tool"
	@echo "    clean    - Clean the project by removing binaries"
	@echo "    fclean   - Clean the project by removing the binaries and the executable"
	@echo "    help     - Prints a help message with target rules"


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
