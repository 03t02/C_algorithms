GCC = gcc

RM = rm -f

CFLAGS = -Wextra -Wall -Werror -pedantic --std=c99

SRCS = main.c \
       ll.c \

OBJS = $(SRCS:.c=.o)

NAME = ll

all: $(NAME)

$(NAME): $(OBJS)
	$(GCC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
