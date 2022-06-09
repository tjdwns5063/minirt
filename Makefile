NAME = miniRT
CC = gcc
CFLAGS = -Wall -Wextra #-Werror

FT_DIR = ./libft/
FT = $(FT_DIR)libft.a

LINK = -L$(FT_DIR) -lft
INCLUDE = -I./incs -I./libft

SRCS_IO = $(addprefix ./srcs/io/, read.c io_utils.c parse.c parse2.c)
SRCS_CHECK = $(addprefix ./srcs/check/, check_format.c check_utils.c)
MAIN = ./srcs/main.c
SRCS = $(SRCS_IO) $(SRCS_CHECK) $(MAIN)
OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(FT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(LINK) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(FT):
	make -C $(FT_DIR) all

clean:
	make -C $(FT_DIR) clean
	rm -rf $(OBJS)

fclean:
	make -C $(FT_DIR) fclean
	rm -rf $(OBJS)
	rm -rf $(NAME)

re: fclean all
