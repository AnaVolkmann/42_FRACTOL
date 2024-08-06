SRCS = main.c string_utils.c
OBJS = $(SRCS:.c=.o)
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I/home/ana-lda-/commoncore-github/42_FRACTOL/minilibx-linux
# Linker Flags
LDFLAGS = -L/home/ana-lda-/commoncore-github/42_FRACTOL/minilibx-linux -lmlx -lXext -lX11 -lm -lz
NAME = fractol

all:		$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@
clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY: all clean re fclean