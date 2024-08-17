# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 00:32:55 by demrodri          #+#    #+#              #
#    Updated: 2024/02/22 00:32:56 by demrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

SRCS			= ft_printf.c\
				  ft_printf_unsigned_int.c\
				  ft_printf_ptr_hex.c\
				  ft_printf_int_str.c \
			      ft_printf_hex_len.c
				    
OBJS			= $(SRCS:.c=.o)

CFLAGS			= -Wall -Wextra -Werror

CC				= gcc

RM 				= rm -f

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)

%.o: %.c		
				@$(CC) $(CFLAGS) -c $< -o $@


all:			$(NAME)
				
clean:			
				@$(RM) $(OBJS) 
				
fclean:			clean
				@$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
