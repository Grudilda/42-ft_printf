# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abonte-b <abonte-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/12 18:00:46 by grudi             #+#    #+#              #
#    Updated: 2024/05/29 12:13:36 by abonte-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

CC			=	cc
CC_FLAGS	=	-Wall -Wextra -Werror

RM			=	rm -f

INC			=	./includes/
HEADER		=	$(INC)ft_printf.h

SRC			=	./sources/
SOURCES		=	$(SRC)ft_printf.c		$(SRC)convert_funct.c \
				$(SRC)dispatch_funct.c	$(SRC)flag_funct_ascii.c \
				$(SRC)flag_funct_nbr.c	$(SRC)init_funct.c \
				$(SRC)print_funct.c		$(SRC)to_str_funct.c

OBJECTS		=	$(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)
	@echo "\033[37;1m$(NAME)         \033[32;1m| creation OK |\033[0;1m"

%.o: %.c $(HEADER)
	@$(CC) $(CC_FLAGS) -c $< -o $@ -I$(INC)

clean:
	@$(RM) $(OBJECTS)
	@echo "\033[37;1mlibftprintf.a objects \033[33;1m|   supp OK   |\033[0;1m"  

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[37;1m$(NAME)         \033[33;1m|   supp OK   |\033[0;1m"
	@echo "\033[34;1m                      | all cleared |"

re: fclean all

.PHONY: all clean fclean re