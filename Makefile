CC = cc
FLAGS = -Wall -Wextra -Werror

HEAD_DIR = includes/
SRCS_DIR = srcs/

NAME = libftprintf.a

FILES = ft_hex.c    ft_pointer.c \
ft_char.c  ft_parse.c  ft_printf.c   ft_string.c   utils2.c\
utils.c  ft_int_dec.c ft_uint.c



OBJS = $(FILES:.c=.o)
OBJS_BONUS = $(FILES_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus : $(NAME)