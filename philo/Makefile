# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 13:05:32 by bapasqui          #+#    #+#              #
#    Updated: 2024/05/03 19:40:53 by bapasqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Don't print any command
ifndef VERBOSE
MAKEFLAGS += --no-print-directory --silent
endif

NAME := philo
CC := cc 
CFLAGS := -Wextra -Wall -Werror -g -O3
DEBUG_FLAGS := -Wextra -Wall -Werror -g -fsanitize=address

SRCS	= 	src/main.c \
			src/init/init.c \
			src/utils/ft_is_digit.c \
			src/utils/ft_atoi.c \
			src/utils/print_error.c \
			src/utils/ft_calloc.c \
			src/utils/ft_free.c \
			src/exec/runtime.c \
			src/utils/ft_lstnew.c \
			src/utils/ft_lst_addback.c \
			src/exec/status.c \
			src/exec/actions.c \
			src/utils/time.c \
			src/exec/monitoring.c \
			src/exec/eating.c \

OBJS_DIR := obj
OBJS    := $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))
all: $(NAME)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_TARGET)
	echo "Compiling\033[1m\033[32m" $@ "\033[0m"
	echo "\033[42mSuccessfully compiled :)\033[0m"

clean:
	rm -rf $(OBJS_DIR)


fclean: clean
	rm -f $(NAME)


re: fclean all
