# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 11:27:34 by lzhansha          #+#    #+#              #
#    Updated: 2020/01/14 18:45:59 by lzhansha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker 
NAME2 = push_swap 

CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBRARIES = -lft -L$(LIBFT_DIR)
INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_DIR)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/

HEADERS_LIST = push_swap.h
HEADERS_DIR = ./includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SOURCES_DIR = ./srcs/
SOURCES_LIST = exec.c\
			stack.c\
			instructs.c\
			instructs_rrr.c\
			utils.c\
			print.c\
			ps_sort.c\
			ps_utils.c\
			ps_utils_two.c\
			ps.c\
			ps_simple.c
SOURCES_LIST_1 = checker.c
SOURCES_LIST_2 = push_swap.c
SOURCES = $(addprefix $(SOURCES_DIR), $(SOURCES_LIST))
SOURCES_1 = $(addprefix $(SOURCES_DIR), $(SOURCES_LIST_1))
SOURCES_2 = $(addprefix $(SOURCES_DIR), $(SOURCES_LIST_2))

OBJECTS_DIR = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS_LIST_1 = $(patsubst %.c, %.o, $(SOURCES_LIST_1))
OBJECTS_LIST_2 = $(patsubst %.c, %.o, $(SOURCES_LIST_2))
OBJECTS	= $(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST))
OBJECTS_1	= $(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST_1))
OBJECTS_2	= $(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST_2))

GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

all: $(NAME1) $(NAME2)

$(NAME1): $(LIBFT) $(OBJECTS_DIR) $(OBJECTS) $(OBJECTS_1)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) $(OBJECTS_1) -o $(NAME1)
	@echo "$(GREEN)./checker is ready to use$(RESET)"

$(NAME2): $(LIBFT) $(OBJECTS_DIR) $(OBJECTS) $(OBJECTS_2)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) $(OBJECTS_2) -o $(NAME2)
	@echo "$(GREEN)./push_swap is ready to use$(RESET)"

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

$(OBJECTS_DIR)%.o : $(SOURCES_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@rm -rf $(OBJECTS_DIR)
	@echo "$(YELLOW)clean is done$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(NAME1)
	@rm -f $(NAME2)
	@echo "$(YELLOW)fclean is done$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
