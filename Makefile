# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: beredzhe <beredzhe@student.42wolfsburg.de> +#+  +:+       +#+        #
#   demacinema <demacinema@student.42.de>        +#+#+#+#+#+   +#+           #
#   Created: 2024/08/12 15:25:18 by both              #+#    #+#             #
#   Updated: 2024/08/12 15:25:55 by both             ###   ########.de       #
#                                                                            #
# ************************************************************************** #

.SILENT:

NAME	= cub3D
cc		= cc
CFLAGS	= -Wall -Wextra -Werror -g -Imlx
MAKEFLAGS += --no-print-directory

SRC_PATH = src/
OBJ_PATH = obj/

HEADER	= include/raytracer.h

SRC		= $(shell find $(SRC_PATH) -name '*.c')
# SRCS	=$(addprefix $(SRC_PATH), $(SRC))

OBJ		= $(SRC:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)
# OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

LIBFT_A	= ./libft/libft.a

# Detect the operating system
UNAME_S := $(shell uname -s)

# Linux
ifeq ($(UNAME_S), Linux)
MLX_DIR = ./minilibx-linux
MLXLIB = $(MLX_DIR)/libmlx.a
MLXFLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
CFLAGS += -D__LINUX__

# macOS
else
MLX_DIR = ./minilibx_opengl_20191021
MLXLIB = $(MLX_DIR)/libmlx.a
MLXFLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
CFLAGS = 
endif
# endif

$(OBJ_PATH)%.o: $(SRC_PATH)%.c  $(HEADER)
	mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@$(MAKE) -C $(MLX_DIR)
	@$(CC) $(OBJ) $(CFLAGS) $(LIBFT_A) $(MLXFLAGS) -o $(NAME)
	@echo "------------------------------"
	@echo "\033[32mProject successfully compiled!\033[0m"
	@echo "------------------------------"

clean:
	@$(MAKE) clean -C $(MLX_DIR)
	@$(MAKE) clean -C libft
	@$(RM) -rf $(OBJ_PATH)
	@echo "---------"
	@echo "\033[31mCleaned!\033[0m"
	@echo "---------"
	
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C libft
	@echo "-------------"
	@echo "\033[31mFull cleaned!\033[0m"
	@echo "-------------"

re: fclean all

.PHONY:	all clean fclean re
