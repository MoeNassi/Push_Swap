NAME = push_swap
SRC = push_swap.c ft_split.c ft_strjoin.c ft_parsing.c ft_isdigit.c ft_lstaddback.c ft_lstaddfront.c \
	ft_lstnew.c ft_error.c argvcheck.c ft_atoi.c ft_strncmp.c mandatory.c ft_lstsize.c mandatory1.c \
	startingLis.c bestmove.c thebestofthebest.c
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