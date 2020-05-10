# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/13 19:08:49 by agrosset          #+#    #+#              #
#    Updated: 2019/05/13 11:59:03 by agrosset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEM_IN		:= lem_in

COLOR_BY = "\033[33;1m"
COLOR_BR = "\033[31;1m"
COLOR_BG = "\033[32;1m"
COLOR_BB = "\033[34;1m"
COLOR_BM = "\033[35;1m"
COLOR_BC = "\033[36;1m"
COLOR_BW = "\033[37;1m"
COLOR_Y = "\033[33m"
COLOR_R = "\033[31m"
COLOR_G = "\033[32m"
COLOR_B = "\033[34m"
COLOR_C = "\033[36m"
COLOR_M = "\033[35m"
COLOR_KW = "\033[37;5m"
COLOR_KR = "\033[31;5m"
COLOR_KG = "\033[32;5m"
COLOR_KB = "\033[34;5m"
COLOR_X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

CC		:= gcc
FLAGS	:= -g -Wall -Wextra -Werror #-g -fsanitize=address

LEM_IN_SRCS_FILES		:=	checker_main.c \
							ft_checker_check_order.c \
							ft_issort_final.c \

LEM_IN_HEADERS_FILES	:=	lem_in.h

SRCS_PATH		:=		srcs/
LEM_IN_PATH		:=		$(SRCS_PATH)checker/
PUSH_SWAP_PATH	:=		$(SRCS_PATH)push_swap/
UTILS_PATH		:=		$(SRCS_PATH)utils/
LIBFT_DIR 		:= 		libft/

LEM_IN_SRCS		:=	$(addprefix $(LEM_IN_PATH), $(LEM_IN_SRCS_FILES))
PUSH_SWAP_SRCS	:=	$(addprefix $(PUSH_SWAP_PATH), $(PUSH_SWAP_SRCS_FILES))
UTILS_SRCS		:=	$(addprefix $(UTILS_PATH), $(UTILS_SRCS_FILES))

OBJS_PATH			:=	objs/
LEM_IN_OBJS_PATH	:=	$(OBJS_PATH)checker/
PUSH_SWAP_OBJS_PATH	:=	$(OBJS_PATH)push_swap/
UTILS_OBJS_PATH		:=	$(OBJS_PATH)utils/
LEM_IN_OBJS		:=	$(addprefix $(LEM_IN_OBJS_PATH), $(LEM_IN_SRCS_FILES:.c=.o))
PUSH_SWAP_OBJS		:=	$(addprefix $(PUSH_SWAP_OBJS_PATH), $(PUSH_SWAP_SRCS_FILES:.c=.o))
UTILS_OBJS			:=	$(addprefix $(UTILS_OBJS_PATH), $(UTILS_SRCS_FILES:.c=.o))

INCLUDES_PATH		:=	includes/
INCLUDE_LIBFT_PATH 	:=	libft/incl/
INCLUDE_LIBFT 		:=	$(INCLUDE_LIBFT_PATH)libft.h
LIBFT				:=	libft/libft.a

INCLUDES		:=	-I $(INCLUDES_PATH) -I ${INCLUDE_LIBFT_PATH}

.PHONY: all clean fclean re

all: $(LEM_IN) $(PUSH_SWAP)

libft/%:
	@(cd $(LIBFT_DIR) && make)

$(UTILS_OBJS_PATH)%.o: $(UTILS_PATH)%.c ${INCLUDE_LIBFT} ${LIBFT}
	@mkdir -p `dirname $@`
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<
	@echo ${COLOR_Y}Compiling [$@]...${COLOR_X}
	@#printf ${UP}${CUT}

$(LEM_IN_OBJS_PATH)%.o: $(LEM_IN_PATH)%.c ${INCLUDE_LIBFT} ${LIBFT}
	@mkdir -p `dirname $@`
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<
	@echo ${COLOR_Y}Compiling [$@]...${COLOR_X}
	@printf ${UP}${CUT}

$(PUSH_SWAP_OBJS_PATH)%.o: $(PUSH_SWAP_PATH)%.c ${INCLUDE_LIBFT} ${LIBFT}
	@mkdir -p `dirname $@`
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<
	@echo ${COLOR_Y}Compiling [$@]...${COLOR_X}
	@printf ${UP}${CUT}

$(LEM_IN): $(UTILS_OBJS) $(LEM_IN_OBJS)
	@$(CC) $(FLAGS) $(LEM_IN_OBJS) $(UTILS_OBJS) ${LIBFT} -o $@
	@echo ${COLOR_G}Success"   "[${LEM_IN}]${COLOR_X}

$(PUSH_SWAP): $(UTILS_OBJS) $(PUSH_SWAP_OBJS)
	@$(CC) $(FLAGS) $(PUSH_SWAP_OBJS) $(UTILS_OBJS) ${LIBFT} -o $@
	@echo ${COLOR_G}Success"   "[${PUSH_SWAP}]${COLOR_X}

clean:
	@echo ${COLOR_R}Cleaning"  "[libft objs]...${COLOR_X}
	@make -C libft/ clean
	@rm -rf $(OBJS_PATH)
	@echo ${COLOR_R}Cleaning"  "[objs]...${COLOR_X}

fclean: clean
	@make -C libft/ fclean
	@rm -f $(LEM_IN) $(PUSH_SWAP)
	@echo ${COLOR_R}Cleaning"  "[${LEM_IN}]...${COLOR_X}
	@echo ${COLOR_R}Cleaning"  "[${PUSH_SWAP}]...${COLOR_X}

re: fclean all
