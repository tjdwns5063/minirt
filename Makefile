NAME = miniRT
M1 = arch -x86_64
CC = gcc
CFLAGS = -Wall -Wextra #-Werror

FT_DIR = ./libft/
FT = $(FT_DIR)libft.a
MINI_LIB_DIR = ./minilibx_opengl/
MINI_LIB = $(MINI_LIB_DIR)libmlx.a

LINK = -L$(MINI_LIB_DIR) -lmlx -framework OpenGL -framework AppKit -L$(FT_DIR) -lft
INCLUDE = -I./incs -I$(FT_DIR) -I$(MINI_LIB_DIR)

SRCS_IO = $(addprefix ./srcs/io/, read.c io_utils.c parse.c parse2.c lst_utils.c\
	print.c print2.c)
SRCS_CHECK = $(addprefix ./srcs/check/, check_format.c check_utils.c check_range.c)
SRCS_INIT = $(addprefix ./srcs/init/, init.c init2.c)
SRCS_CALC = $(addprefix ./srcs/calc/, vec_calc.c)
SRCS_RENDER = $(addprefix ./srcs/render/, render.c)
SRCS_HIT = $(addprefix ./srcs/hit/, hit_shape.c)

MAIN = ./srcs/main.c
SRCS = $(SRCS_IO) $(SRCS_CHECK) $(SRCS_INIT) $(SRCS_CALC) $(SRCS_RENDER) $(SRCS_HIT) $(MAIN)
OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(MINI_LIB) $(FT) $(OBJS)
	$(M1) $(CC) $(CFLAGS) $(INCLUDE) $(LINK) $(OBJS) -o $@

%.o: %.c
	$(M1) $(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(FT):
	$(M1) make -C $(FT_DIR) all

$(MINI_LIB):
	$(M1) make -C $(MINI_LIB_DIR) all

clean:
	$(M1) make -C $(FT_DIR) clean
	$(M1) make -C $(MINI_LIB_DIR) clean
	rm -rf $(OBJS)

fclean:
	$(M1) make -C $(FT_DIR) fclean
	$(M1) make -C $(MINI_LIB_DIR) clean
	rm -rf $(OBJS)
	rm -rf $(NAME)

re: fclean all
