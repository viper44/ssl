# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msemenov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/23 14:54:01 by msemenov          #+#    #+#              #
#    Updated: 2018/01/23 14:54:03 by msemenov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = /mnt/c/Users/viper/Desktop/ft_printf/printf.h
FLAGS = -Wall -Wextra -Werror
HDR = -c -I $(HEADER)
SRC_INT = ./srcs/int/ft_add_plus.c ./srcs/int/ft_add_space.c ./srcs/int/ft_aligning_number_sleva.c    \
./srcs/int/ft_aligning_number_sprava.c ./srcs/int/ft_kostil.c ./srcs/int/ft_output.c                  \
./srcs/int/ft_output_number.c ./srcs/int/itoa_base.c ./srcs/int/unsigned_itoa.base.c                  \
./srcs/int/ft_plus_minus_space.c
SRC_BASIC = ./srcs/basic/ft_atoi.c ./srcs/basic/ft_check_conv.c ./srcs/basic/ft_get_data.c            \
./srcs/basic/ft_get_width.c ./srcs/basic/ft_isdigit.c ./srcs/basic/ft_strjoin.c                       \
./srcs/basic/ft_strlen.c ./srcs/basic/ft_strnew.c ./srcs/basic/ft_strncpy.c  \
./srcs/basic/ft_strsub.c ./srcs/basic/ft_strdup.c ./srcs/basic/ft_memset.c
SRC_OCTET = ./srcs/octet/ft_aligning_number_sleva_octet.c ./srcs/octet/ft_hash.c                      \
./srcs/octet/ft_aligning_number_sprava_octet.c ./srcs/octet/ft_output_octet.c                         \

SRC_HEX = ./srcs/hex/ft_output_hex.c ./srcs/hex/ft_hash_hex.c ./srcs/hex/ft_output_hex_b.c            \
./srcs/hex/ft_hash_hex_b.c ./srcs/hex/unsigned_itoa.base_sx.c ./srcs/hex/ft_aligning_number_sleva_hex.c \
./srcs/hex/ft_aligning_number_sprava_hex.c ./srcs/hex/ft_aligning_number_sprava_hex_b.c               \
./srcs/hex/ft_aligning_number_sleva_hex_b.c                                                           \

SRC_UN_INT = ./srcs/unsigned_int/ft_output_un_int.c ./srcs/unsigned_int/ft_output_unb_int.c           \

SRC_CHAR = ./srcs/char/ft_output_char.c ./srcs/char/ft_output_char_uni.c                              \
./srcs/char/ft_aligning_char_uni_sleva.c ./srcs/char/ft_aligning_char_uni_sprava.c                    \
./srcs/char/ft_aligning_char_sleva.c ./srcs/char/ft_aligning_char_sprava.c
SRC_STRING_UNI = ./srcs/string_uni/ft_output_string_uni.c ./srcs/string_uni/ft_aligning_string_uni.c  \

SRC_STRING = ./srcs/string/ft_output_string.c ./srcs/string/ft_alignin_string_sleva.c                 \
./srcs/string/ft_aligning_string_sprava.c
SRC_POINTER = ./srcs/pointer/ft_output_pointer.c ./srcs/pointer/ft_aligning_pointer_sprava.c          \
./srcs/pointer/ft_aligning_pointer_sleva.c
PRINTF = ./ft_printf.c
OBJ = ft_add_plus.o ft_add_space.o ft_aligning_number_sleva.o ft_aligning_number_sprava.o             \
ft_kostil.o ft_output.o ft_output_number.o itoa_base.o unsigned_itoa.base.o ft_atoi.o ft_check_conv.o \
ft_get_data.o ft_get_width.o ft_isdigit.o ft_strjoin.o ft_strlen.o ft_strnew.o ft_printf.o            \
ft_output_octet.o ft_aligning_number_sprava_octet.o ft_aligning_number_sleva_octet.o ft_hash.o        \
ft_output_hex.o ft_hash_hex.o ft_output_hex_b.o ft_hash_hex_b.o unsigned_itoa.base_sx.o               \
ft_output_un_int.o ft_output_char.o ft_strncpy.o ft_output_string.o ft_alignin_string_sleva.o         \
ft_strsub.o ft_aligning_string_sprava.o ft_strdup.o ft_aligning_number_sleva_hex.o                    \
ft_aligning_number_sprava_hex.o ft_aligning_number_sleva_hex_b.o ft_aligning_number_sprava_hex_b.o    \
ft_output_unb_int.o ft_aligning_char_uni_sleva.o ft_output_char_uni.o ft_aligning_char_uni_sprava.o   \
ft_output_string_uni.o ft_output_pointer.o ft_aligning_char_sleva.o ft_aligning_string_uni.o          \
ft_aligning_char_sprava.o ft_aligning_pointer_sprava.o ft_aligning_pointer_sleva.o ft_memset.o        \
ft_plus_minus_space.o

all:$(NAME)

$(NAME):
		@ gcc $(FLAGS) $(SRC_BASIC) $(SRC_CHAR) $(SRC_POINTER) $(SRC_STRING_UNI) $(SRC_STRING) $(SRC_INT) $(SRC_UN_INT) $(SRC_HEX) $(SRC_OCTET) $(PRINTF) $(HDR)
		@ ar rc $(NAME) $(OBJ)
		

clean:
		@ /bin/rm -f $(OBJ)

fclean: clean
		@ /bin/rm -f $(NAME)

re: fclean all