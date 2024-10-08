SRCS = main.c string_utils.c render.c init.c math_utils.c events.c
OBJS = $(SRCS:.c=.o)
CC = cc
RM = rm -f
CFLAGS = -g -Wall -Werror -Wextra -I/home/ana-lda-/commoncore-github/42_FRACTOL/minilibx-linux
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