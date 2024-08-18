CC = gcc

CFLAGS = -Wall -Wextra -Werror -I./includes

# LDFLAGS = -lmlx -lX11 -lXext -lm
LDFLAGS = -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit

SRCS = screen.c \
		main.c \
		map.c \
		raycharles.c \
		cub3d_utils.c \
		player.c

OBJDIR = obj
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
GNL_OBJS = libft/gnl/get_next_line.o libft/gnl/get_next_line_utils.o

LIBFT_DIR		= libft
LIBFT			= $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = libft/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

NAME = cub3d

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME): $(OBJS) $(GNL_OBJS) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(OBJS) $(GNL_OBJS) -o $(NAME) $(LIBFT) $(FT_PRINTF) $(LDFLAGS)
	@./$(NAME) map.cub

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	@rm -rf $(OBJDIR)

fclean: clean
	@# @$(MAKE) -C $(LIBFT_DIR) fclean
	@# @$(MAKE) -C $(FT_PRINTF_DIR) fclean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re