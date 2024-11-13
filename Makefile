CC = cc
FLAGS = -Wall -Wextra -Werror

HEAD_DIR = includes/
SRCS_DIR = srcs/

NAME = libftprintf.a

FILES = ft_printf.c  utils.c  ft_string.c  ft_parse.c


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
