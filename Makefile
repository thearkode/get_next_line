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

CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=42

HEADERS = get_next_line.h

SRC = get_next_line.c get_next_line_utils.c

SRC_B = 

OBJ = $(addprefix $(OBJ_DIR),$(SRC:.c=.o))
OBJ_DIR = obj/
OBJ_B = $(addprefix $(OBJ_B_DIR),$(SRC_B:.c=.o)) #obj_b/ft_lstnew.o
OBJ_B_DIR = obj_b/

all: $(NAME)

bonus: ${OBJ_B}
	@ar rcs ${NAME} $(OBJ_B)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN) get_next_line [$(NAME)] created!$(RESET)"

$(OBJ_DIR)%.o: %.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

$(OBJ_B_DIR)%.o: %.c
	@mkdir -p obj_b
	$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Objects Removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Executable Removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re