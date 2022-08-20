NAME = libftprintf.a

INCLUDE = include
RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Werror -Wextra -I
FILES = ft_printf.c ft_print_nosign.c ft_printf_others.c ft_print_ptr.c ft_print_hex.c
OBJS = $(FILES:.c=.o)
LIB_DIR = lib/
CC = gcc

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

all: ${NAME}

${NAME}: $(OBJS)
	make -C $(LIB_DIR)
	cp lib/libft.a .
	mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) ${NAME}

re: fclean all

.PHONY: all clean fclean re