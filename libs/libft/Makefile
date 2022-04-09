# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrossig <adrossig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/25 15:54:34 by adrossig          #+#    #+#              #
#    Updated: 2020/01/04 16:30:07 by null             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = clang
FLAGS = -W -Wall -Werror -Wextra -g3 -O3 -emit-llvm
INC = ./includes/

T_BLK = \033[5m
T_NRM = \033[25m
T_CLR = \033[K
C_YLW = \033[33m
C_GRN = \033[32m
C_LYLW = \033[93m
C_LGRN = \033[92m
C_LMGN = \033[95m
C_END = \033[0m

ARRAY := ft_array_erase.c ft_array_lenght.c ft_array_putstr.c \
		ft_array_reverse.c ft_array_swap.c ft_arrayadd_value.c \
		ft_arraydel_value.c ft_arraylst_free.c

CHAR := ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isblank.c ft_iscntrl.c \
		ft_isdigit.c ft_isgraph.c ft_islower.c ft_isprint.c ft_ispunct.c ft_isspace.c \
		ft_isupper.c ft_tolower.c ft_toupper.c ft_charset.c

CONV := ft_atoi.c ft_itoa.c ft_bintodec.c ft_bintohexa.c ft_bintooctal.c \
		ft_dectobin.c ft_dectohexa.c ft_dectooctal.c ft_hexatooctal.c \
		ft_octaltobin.c ft_octaltodec.c ft_tohexa.c ft_itoa_base.c \
		ft_itoa_uimax.c ft_uitoa.c ft_lltoa.c ft_lltoa_base.c \
		ft_atoill.c ft_atoi_base.c \
		ft_base.c

CRYPT := ft_crypt_str.c ft_uncrypt_str.c

DICT := ft_add_item_label.c ft_destroy.c ft_get_element_index.c \
		ft_get_element_label.c ft_gethash.c ft_init_dict.c

LST :=  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstlast.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lst_append.c \
		ft_lst_putendl.c ft_lst_putstr.c ft_lst_putstr_fd.c \
		ft_lstlenght.c ft_lst_addlast.c ft_lst_free.c

MALLOC :=	ft_calloc.c

MATH := ft_fibonacci.c ft_is_prime.c ft_power.c ft_sqrt.c ft_swap.c \
		ft_armstrong.c ft_gcd.c ft_lcm.c ft_palindrome.c ft_abs.c \
		ft_int_length_uimax.c  ft_surface.c

MEM :=  ft_bzero.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c

PRINT :=	ft_putchar.c ft_putnbr.c ft_putstr.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_putendl.c ft_putnstr.c ft_putuint_base_fd.c

SORT :=	ft_bubblesort.c ft_insertsort.c ft_selectsort.c

STR :=	ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
		ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
		ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
		ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strndup.c ft_strnequ.c \
		ft_strnew.c ft_strnstr.c ft_strrchr.c ft_split.c ft_substr.c \
		ft_strtrim.c ft_strlcpy.c ft_strfree.c ft_strnlen.c \
		ft_strrev.c ft_tolower_str.c ft_toupper_str.c ft_strchr_index.c \
		ft_strchsep.c ntm.c

VECTOR := ft_vector_base.c ft_vector_insert.c ft_vector_delete.c

NUMBER := ft_intlen.c ft_uintlen.c ft_hexintlen.c ft_long_hexintlen.c

WCHAR :=	ft_putwchar.c ft_putwchar_fd.c ft_putwstrn.c ft_putwstr_fd.c ft_wstrlen.c \
			ft_wchar_len.c

GNL := get_next_line.c gnl_util.c

MATRIX := ft_extend_matrix.c ft_free_matrix.c ft_matrix_len.c ft_matrix_replace_in.c \
			ft_matrix_putfd.c ft_dup_matrix.c

FILES := $(addprefix char/, $(CHAR)) \
	$(addprefix conv/, $(CONV)) \
	$(addprefix lst/, $(LST)) \
	$(addprefix math/, $(MATH)) \
	$(addprefix mem/, $(MEM)) \
	$(addprefix print/, $(PRINT)) \
	$(addprefix str/, $(STR)) \
	$(addprefix sort/, $(SORT)) \
	$(addprefix malloc/, $(MALLOC)) \
	$(addprefix vector/, $(VECTOR)) \
	$(addprefix crypt/, $(CRYPT)) \
	$(addprefix dict/, $(DICT)) \
	$(addprefix number/, $(NUMBER)) \
	$(addprefix array/, $(ARRAY)) \
	$(addprefix wchar/, $(WCHAR)) \
	$(addprefix gnl/, $(GNL)) \
	$(addprefix matrix/, $(MATRIX)) \

SRC := $(addprefix src/, $(FILES))
OBJ := $(SRC:%.c=%.o)

NB = $(words $(FILES))
IND = 0
PER = 0

all: $(NAME)

$(OBJ): %.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INC)
	@$(eval IND=$(shell echo $$(($(IND) + 1))))
	@$(eval PER=$(shell echo $$((($(IND) * 100) / $(NB)))))
	@printf "$(T_CLR)$(C_LYLW)➜ ➜ progress: %3d %% $(C_END)\n\033[1A$(C_END)" $(PER);

$(NAME):
	@echo "$(C_LYLW)➜ [$(NAME)] Compiling objects ... $(C_END)"
	@make $(OBJ)
	@echo "\033[1A$(T_CLR)$(C_LGRN)➜ [$(NAME)] Objects have been compiled successfully ! $(C_END)"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(C_LGRN)➜ [$(NAME)] Library has been Compiled Successfully !$(C_END)"

clean:
	@rm -f $(OBJ) $(OBONUS)
	@echo "$(C_LMGN)➜ [$(NAME)] Objects have been cleaned Successfully !$(C_END)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(C_LMGN)➜ [$(NAME)] Library has been deleted Successfully !$(C_END)"

re: fclean all
	@echo "$(C_LGRN)➜ [$(NAME)] Library has been re-builded\
	 Successfully !$(C_END)"

norm:
	@norminette $(SRC) $(INC)
	@echo "[$(C_LGRN)➜ [$(NAME)] Files analized $(C_END)]"

.PHONY: clean fclean re
