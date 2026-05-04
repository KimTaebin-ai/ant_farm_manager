# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 23:49:28 by taebkim           #+#    #+#              #
#    Updated: 2026/05/04 22:10:40 by taebkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror -I$(INCS_DIR)
CC = cc
AR = ar rcs
RM = rm -f

LIBFT = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
        ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
        ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
        ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strcmp.c ft_memchr.c ft_memcmp.c \
        ft_strnstr.c ft_atoi.c ft_atod.c ft_calloc.c ft_strdup.c ft_substr.c \
        ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
        ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
        ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
        ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c

GNL = get_next_line.c \
      get_next_line_utils.c

FT_PRINTF = ft_printf.c func.c func2.c convert_hex.c

INCS_DIR = ./includes
OBJ_DIR = ./obj

LIBFT_DIR = ./srcs/libft
FT_PRINTF_DIR = ./srcs/ft_printf
GNL_DIR = ./srcs/get_next_line

SRCS = $(addprefix $(LIBFT_DIR)/, $(LIBFT)) \
       $(addprefix $(FT_PRINTF_DIR)/, $(FT_PRINTF)) \
       $(addprefix $(GNL_DIR)/, $(GNL))

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(LIBFT_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(FT_PRINTF_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
