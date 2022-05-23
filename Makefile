# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apaula-r <apaula-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 15:54:50 by apaula-r          #+#    #+#              #
#    Updated: 2021/11/10 16:16:20 by apaula-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


GREEN = \033[0;32m
GREENGREEN = \033[38;5;46m
RED = \033[0;31m
BLUE = \033[0;34m
GREY = \033[38;5;240m
RESET = \033[0m


NAME = get_next_line.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=1

HEADERS = get_next_line.h

SRC = get_next_line.c get_next_line_utils.c

all: $(NAME)

$(NAME): $(OBJ)
	gcc ${CFLAGS} ${SRC} -o $(NAME)
	@echo "$(GREEN) get_next_line [$(NAME)] created!$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Objects Removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Executable Removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re