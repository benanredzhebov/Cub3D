# Makefile for the raytracer project

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -I./includes

# Linker flags
LDFLAGS = -lmlx -lX11 -lXext -lm

# Source files
SRCS = main.c raytracer.c

# Object files
OBJS = $(SRCS:.c=.o)

# Output executable
NAME = cub3d

# Default target
all: $(NAME)

# Rule to link object files into the executable
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to remove object files
clean:
	rm -f $(OBJS)

# Rule to remove object files and the executable
fclean: clean
	rm -f $(NAME)

# Rule to recompile everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
