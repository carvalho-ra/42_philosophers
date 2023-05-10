NAME = philo

SRCS =	./src/utils.c \
		./src/validation.c \
		./src/philo.c \

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
