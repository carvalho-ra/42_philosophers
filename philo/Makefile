NAME = philo

SRCS = ./src/philo.c \
		./src/init.c \
		./src/time.c \
		./src/utils.c \
		./src/validation.c \
		./src/actions.c \
		./src/monitor.c \

OBJS = $(SRCS:.c=.o)

CC = cc -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all libft clean fclean re
