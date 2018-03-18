# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msemenov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/16 09:24:45 by msemenov          #+#    #+#              #
#    Updated: 2018/03/16 09:24:46 by msemenov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl
SRCDIR = ./src/
SRCNAMES = $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRC = $(addprefix $(SRCDIR), $(SRCNAMES))
INC = ./
OBJECTS = ./objects/
BUILDOBJS = $(addprefix $(OBJECTS), $(SRCNAMES:.c=.o))
LIBDIR = ./libft/
PRINTFDIR = ./printf/
PRINTF = ./printf/libftprintf.a
PRINTFINC = ./printf/
LIBFT = ./libft/libft.a
LIBINC = ./libft/
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJECTS):
	mkdir -p $(OBJECTS)

$(OBJECTS)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) -I$(LIBINC) -I$(PRINTFINC) -I$(INC) -o $@ -c $<

$(NAME): $(OBJECTS) $(LIBFT) $(PRINTF) $(BUILDOBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(BUILDOBJS) $(LIBFT) $(PRINTF)

$(LIBFT):
	make -C $(LIBDIR)
$(PRINTF):
	make -C $(PRINTF)
clean:
	rm -rf $(OBJECTS)
	make -C $(LIBDIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBDIR) fclean

re: fclean all

.PHONY: all fclean clean re
