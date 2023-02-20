NAME = push_swap
BNAME = checker
SRC = push_swap.c ft_split.c ft_strjoin.c ft_parsing.c ft_isdigit.c ft_lstaddback.c ft_lstaddfront.c \
	ft_lstnew.c ft_error.c argvcheck.c ft_atoi.c ft_strncmp.c mandatory.c ft_lstsize.c mandatory1.c \
	startingLis.c bestmove.c thebestofthebest.c mandatory2.c freelist.c
BNS = bonus/push_swap_b.c mandatory.c mandatory1.c ft_strncmp.c ft_lstnew.c ft_lstaddfront.c ft_lstsize.c \
	ft_lstaddback.c ft_atoi.c ft_parsing.c ft_split.c argvcheck.c ft_error.c ft_isdigit.c ft_strjoin.c mandatory2.c \
	freelist.c
HEAD = push_swap.h
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

bonus : $(BNAME)

$(NAME) : $(SRC) $(HEAD)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) libftprintf.a

$(BNAME) : $(BNS) $(HEAD)
	$(CC) $(CFLAGS) $(BNS) -o $(BNAME) libftprintf.a get_next_line.a

clean :
	rm -rf $(NAME)

fclean : clean
	rm -rf $(BNAME)

re : fclean all

.PHONY : bonus fclean clean re