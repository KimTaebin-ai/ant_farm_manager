# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/24 02:52:49 by taebkim           #+#    #+#              #
#    Updated: 2026/05/04 19:29:16 by taebkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

INCS_DIR = ./includes

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCS_DIR) -Ilibft/$(INCS_DIR)
RM = rm -f

LIBFT_DIR = ./libft
LIBFT_NAME = libft.a
LIBFT = $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

OBJ_DIR = obj

SRCS = $(addprefix src/, \
	main.c \
)

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(LIBFT) $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re