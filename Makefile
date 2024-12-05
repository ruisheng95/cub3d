SRCS = \
main.c parsing1.c parsing_utils.c utils.c checkmap.c background.c \
player1.c print.c raycast.c movement.c draw.c handle.c player2.c handle_fts.c \
utils2.c init.c

TESTIMG = testimg.c

OBJ = $(SRCS:.c=.o)

NAME = cub3d

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIB = libft.a

LIBDIR = libft

OS:=$(shell uname)
ifeq ($(OS), Linux)
	MINILIBX_DIR=minilibx-linux
	MINILIBX_FLAG=-L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm
	DEP_MINILIBX=$(MINILIBX_DIR)/libmlx.a
else
	MINILIBX_DIR=.
	MINILIBX_FLAG=-L$(MINILIBX_DIR) -lmlx -framework OpenGL -framework AppKit -L/usr/X11/lib
	DEP_MINILIBX=libmlx.a
endif


all : $(NAME)

$(NAME): $(OBJ) $(LIB) $(DEP_MINILIBX) Makefile
	@$(CC) $(OBJ) $(MINILIBX_FLAG) -o $(NAME) $(LIB)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(LIB) : 
	@$(MAKE) -C $(LIBDIR)
	@mv $(LIBDIR)/$(LIB) .

clean :
	@rm -f ${OBJ}
	@rm -f $(LIB)
	$(MAKE) -C $(LIBDIR) clean

fclean : clean
	@rm -f $(NAME)

testimg: $(OBJ) $(LIB)
	@$(CC) $(TESTIMG) -lft $(MINILIBX_FLAG) -o $(NAME) $(LIB)

test: $(OBJ) $(LIB)
	@$(CC) test.c -lft $(MINILIBX_FLAG) $(LIB)

re : fclean all



.PHONY: all clean fclean re leak