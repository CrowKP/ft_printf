NAME = libftprintf.a

RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Werror -Wextra
FILES = ft_printf.c 
OBJS = $(FILES:.c=.o)
LIB_DIR = lib/
CC = gcc
HEADER = ft_printf.h

.c.o:
	$(CC) $(CFLAGS) -g -c $< -o $(<:.c=.o)

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