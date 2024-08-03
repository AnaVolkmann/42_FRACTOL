SRCS = main.c string_utils.c
OBJS = $(SRCS:.c=.o)
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
NAME = fractol

all:		$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
				$(CC) $(CFLAGS) -c -o $@ $<

clean:
				$(RM) $(OBJS)

fclean:			clean
						$(RM) $(NAME)

re:				fclean all

.PHONY: all clean re