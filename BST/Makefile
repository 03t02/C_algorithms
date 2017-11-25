GCC = gcc

RM = rm -f

CFLAGS = -Wextra -Wall -Werror -pedantic --std=c11

SRCS = main.c \
       BST.c \

OBJS = $(SRCS:.c=.o)

NAME = bst

all: $(NAME)

$(NAME): $(OBJS)
	$(GCC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
