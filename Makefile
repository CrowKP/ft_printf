NAME = libftprintf.a

INCLUDE = -I include
RM = rm -f
AR = ar -rcs
CFLAGS = -Wall -Werror -Wextra -MMD 
FILES = ft_printf.c ft_print_nosign.c ft_printf_others.c ft_print_ptr.c ft_print_hex.c
OBJS = $(FILES:.c=.o)
LIB_DIR = lib/
LIB_DIR_F= lib/*.c
RM_DEPS = *.d
LIB_DIR_DEPS = lib/*.d
LIB_DIR_OBJ = lib/*.o
CC = gcc
DEPS = $(addsuffix .d, $(basename $(FILES)))
HEADER = include/ft_printf.h include/libft.h

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

all: $(NAME)

-include $(DEPS)
$(NAME): $(OBJS)
	make -C $(LIB_DIR)
	cp lib/libft.a .
	mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)
	ranlib $(NAME)

-include $(DEPS)
exec:
	$(CC) $(CFLAGS) $(INCLUDE) $(FILES) $(LIB_DIR_F) main.c

clean:
	$(RM) $(OBJS) $(LIB_DIR_OBJ)
	$(RM) $(DEPS) lib/libft.a
	$(RM) $(RM_DEPS) $(LIB_DIR_DEPS)

fclean: clean
	$(RM) $(NAME) a.out

re: fclean all

.PHONY: all clean fclean re
