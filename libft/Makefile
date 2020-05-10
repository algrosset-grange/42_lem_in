# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 13:55:55 by agrosset          #+#    #+#              #
#    Updated: 2017/05/06 06:04:44 by agrosset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC = -I ./incl/

FLAGS = -Wall -Wextra -Werror

SRCS_BOOL =		ft_intarray_is_sorted.c \
				ft_is_alrdy_contained.c \
				ft_is_integer.c \
				ft_is_power_of_2.c \
				ft_is_power_of_x.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isblank.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_isspace.c \
				ft_iswascii.c

SRC_IMG		=	ft_init_img.c \
				ft_put_pixel.c \

SRCS_IO =		ft_putchar_fd.c \
				ft_putchar.c \
				ft_putendl_fd.c \
				ft_putendl.c \
				ft_puthex.c \
				ft_putnbr_base.c \
				ft_putnbr_fd.c \
				ft_putnbr.c \
				ft_putstr_fd.c \
				ft_putstr_free.c \
				ft_putstr.c \
				ft_putwchar.c \
				ft_putwstr.c \
				get_next_line.c \

SRCS_LST =		ft_lst_reverse.c \
				ft_lstadd.c \
				ft_lstaddend.c \
				ft_lstdel.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstswap.c \

SRCS_MATHS =	ft_abs.c \
				ft_atoi.c \
				ft_clamp.c \
				ft_fclamp.c \
				ft_get_median.c \
				ft_htoi.c \
				ft_nbrlen.c \
				ft_pow.c \
				ft_rand.c \
				ft_range.c \
				ft_round.c \

SRCS_MEM =		ft_bubblesort_array.c \
				ft_bzero.c \
				ft_free_chartab.c \
				ft_intnew.c \
				ft_memalloc.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memdel.c \
				ft_memmove.c \
				ft_memset.c \
				ft_memswap.c \
				ft_realloc.c \
				ft_strnew.c \
				ft_swap.c \

SRCS_PRINTF	=	ft_printf.c \
				pf_bonus.c \
				pf_buffer.c \
				pf_number.c \
				pf_parsing.c \
				pf_string.c \

SRCS_STR =		ft_error.c \
				ft_exit_error.c \
				ft_name.c \
				ft_str2lower.c \
				ft_strappend.c \
				ft_strcat.c \
				ft_strchr_index.c \
				ft_strchr.c \
				ft_strclr.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strctrim.c \
				ft_strdel.c \
				ft_strdup.c \
				ft_strdupfree.c \
				ft_strequ.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strjoinfree.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strlencmp.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strncat.c \
				ft_strncmp.c \
				ft_strncpy.c \
				ft_strndup.c \
				ft_strnequ.c \
				ft_strnjoin.c \
				ft_strnjoinfree.c \
 				ft_strnstr.c \
				ft_strrchr.c \
				ft_strrev.c \
				ft_strsplit.c \
				ft_strstr.c \
				ft_strsub.c \
				ft_strtrim.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_woco.c \

SRCS_TOA =		ft_itoa_base.c \
				ft_itoa.c \
				ft_ldtoa.c \
				ft_lltoa_base.c \
				ft_ulltoa_base.c \

SRCS_UNICODE =	ft_wcharlen.c \
				ft_wstrdup.c \
				ft_wstrjoin.c \
				ft_wstrlen.c \
				ft_wstrsub.c \


### PATH ###
SRCS_PATH = srcs/
SRCS =	$(addprefix $(SRCS_PATH)srcs_bool/, $(SRCS_BOOL)) \
	   	$(addprefix $(SRCS_PATH)srcs_io/, $(SRCS_IO)) \
	   	$(addprefix $(SRCS_PATH)srcs_lst/, $(SRCS_LST)) \
	   	$(addprefix $(SRCS_PATH)srcs_maths/, $(SRCS_MATHS)) \
	   	$(addprefix $(SRCS_PATH)srcs_mem/, $(SRCS_MEM)) \
		$(addprefix $(SRCS_PATH)srcs_printf/, $(SRCS_PRINTF)) \
	   	$(addprefix $(SRCS_PATH)srcs_str/, $(SRCS_STR)) \
	   	$(addprefix $(SRCS_PATH)srcs_toa/, $(SRCS_TOA)) \
	   	$(addprefix $(SRCS_PATH)srcs_unicode/, $(SRCS_UNICODE)) \


OBJ_PATH  = obj/
OBJ = 	$(addprefix $(OBJ_PATH)srcs_bool/, $(SRCS_BOOL:.c=.o)) \
	   	$(addprefix $(OBJ_PATH)srcs_io/, $(SRCS_IO:.c=.o)) \
	   	$(addprefix $(OBJ_PATH)srcs_lst/, $(SRCS_LST:.c=.o)) \
	   	$(addprefix $(OBJ_PATH)srcs_maths/, $(SRCS_MATHS:.c=.o)) \
	   	$(addprefix $(OBJ_PATH)srcs_mem/, $(SRCS_MEM:.c=.o)) \
		$(addprefix $(OBJ_PATH)srcs_printf/, $(SRCS_PRINTF:.c=.o)) \
	   	$(addprefix $(OBJ_PATH)srcs_str/, $(SRCS_STR:.c=.o)) \
	   	$(addprefix $(OBJ_PATH)srcs_toa/, $(SRCS_TOA:.c=.o)) \
	   	$(addprefix $(OBJ_PATH)srcs_unicode/, $(SRCS_UNICODE:.c=.o)) \

### COMPILE ###
UP	=	"\033[A"
CUT	=	"\033[K"

all:	$(NAME)
		
$(NAME):$(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
		@echo "\033[34m\033[1mCompilation of \033[0m\033[36m$(notdir $<)\033[1m\033[34m done.\033[0m"
		@/bin/mkdir -p `dirname $@`
		@gcc -c $(FLAGS) $(INC) $< -o $@
		@printf $(UP)$(CUT)

clean:
		@/bin/rm -rf $(OBJ_PATH)
		@echo "\033[1;31m$(NAME) \033[1;0m\033[31mobjects files removed.\033[0m"

fclean:	clean
		@/bin/rm -rf $(NAME)
		@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re:		fclean all

.PHONY:	all, clean, fclean, re
