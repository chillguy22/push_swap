CC = gcc
CFLAGS = -Wall -Wextra -Werror
C_PRECOMPILE_FLAGS = -c
C_DEBUG_FLAG = -g

NAME = push_swap
SRCS = push_swap.c \
       algorithm.c \
       errors.c \
       operations.c \
       push_swap1.c \
       push.c \
       rotate.c \
       setup.c \
       sort.c \
       stuff.c \
       update.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) $(C_PRECOMPILE_FLAGS) $< -o $@ 

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

debug: $(LIBFT)
	$(CC) $(CFLAGS) $(C_DEBUG_FLAG) $(SRCS) -o $(NAME)

clean:
	$(MAKE) clean -C
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus