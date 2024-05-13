##
## EPITECH PROJECT, 2022
## Lib Makefile
## File description:
## makefile for my library
##

CFLAGS += -Imy/include/ -W -Wall -Wextra -pedantic

SRC	=	my_io/my_put_float.c\
		my_io/my_put_nbr_unsigned.c\
		my_io/my_put_nbr.c\
		my_io/my_put_printable.c\
		my_io/my_putbase.c\
		my_io/my_putchar.c\
		my_io/my_putstr.c\
		my_io/my_readfile.c\
		my_io/my_read_file_old.c\
		my_math/my_compute_power_rec.c\
		my_math/my_compute_square_root.c\
		my_math/my_find_prime_sup.c\
		my_math/my_is_prime.c\
		my_math/my_sort_int_array.c\
		my_math/my_swap_int.c\
		my_printf/my_printf.c\
		my_printf/flags/base_conv_flags.c\
		my_printf/flags/char_conv_flags.c\
		my_printf/flags/number_conv_flags.c\
		my_str/my_revstr.c\
		my_str/my_str_isalpha.c\
		my_str/my_str_isnum.c\
		my_str/my_str_to_word_array.c\
		my_str/my_strcat_new.c\
		my_str/my_strcmp.c\
		my_str/my_strcpy.c\
		my_str/my_strdup.c\
		my_str/my_strlen.c\
		my_str/my_strncpy.c\
		my_str/my_str_countchar.c\
		my_str/my_realloc_str.c\
		my_math/my_atoi.c\
		my_math/my_atof.c\
		others/my_is_between.c\
		my_str/my_str_extract.c\
		my_io/my_readfd.c\
		my_str/my_str_find.c\
		my_io/my_fd_to_fd.c\
		my_str/my_str_in.c\
		my_str/my_str_case.c\
		my_str/my_str_has_prefix.c\
		my_f_io/my_fputbase.c\
		my_f_io/my_fputchar.c\
		my_f_io/my_fputnbr.c\
		my_f_io/my_fputstr.c\
		my_f_io/my_fputnbr_unsigned.c\
		my_f_io/my_fputfloat.c\
		my_fprintf/my_fprintf.c\
		my_fprintf/flags/base_conv_flags.c\
		my_fprintf/flags/char_conv_flags.c\
		my_fprintf/flags/number_conv_flags.c\

SRC := $(addprefix my/, $(SRC))

OBJ	=	$(SRC:.c=.o)

libmy.a:	$(OBJ)
	ar rc libmy.a $(OBJ)

all: libmy.a

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f libmy.a
	rm -f libdebug.a

re: fclean all

libdebug.a: CFLAGS += -g
libdebug.a: $(OBJ)
	ar rc libdebug.a $(OBJ)

debug: libdebug.a

.PHONY: all clean fclean re debug
