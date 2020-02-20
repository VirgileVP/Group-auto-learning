NAME = auto_learn

CC = gcc
INCLUDES = $(addprefix -I, includes)
CFLAGS = -g -Wall -Werror -Wextra

LIB = libft/libft.a

OBJ_DIR = ./objs/
SRC_DIR = ./srcs/

SRC = main.c \
	  param.c \
	  learn.c \
	  tools.c \
	  adjustment.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))


all:$(NAME)

$(NAME):$(OBJ) $(LIB)
	$(CC) -Llibft -lft $^ -o $@

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@

$(LIB):
	make -C libft

clean:
	make clean -C libft
	rm -rf $(OBJ)

fclean:clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean
	make all

.PHONY: clean flclean re all
