NAME = push_swap
SRC = push_swap.c ft_split.c ft_strjoin.c ft_parsing.c ft_isdigit.c ft_error.c argvcheck.c ft_atoi.c
HEAD = push_swap.h
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) libftprintf.a

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all

.PHONY : fclean clean re