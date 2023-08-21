D_SRC = ./src/
SRC = main.c client/my_client_leave.c client/my_client_read.c client/my_client_utils.c client/my_client_reset.c client/my_client_join.c socket/my_socket_reset.c socket/my_socket_create.c socket/my_socket_utils.c socket/my_socket_write.c socket/my_socket_close.c

D_OBJ = ./obj/
OBJ = $(addprefix $(D_OBJ), $(patsubst %.c,%.o,$(SRC)))

D_INC = ./inc/
S_INC = my_socket.h
INC = $(addprefix $(D_INC), $(S_INC))

CC = cc
FLAGS = -Wall -Wextra -Werror -g

NAME = socket

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o$@

$(OBJ): $(D_OBJ)%.o : $(D_SRC)%.c $(INC)
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -I$(D_INC) -c $< -o $@

clean:
	rm -rf $(D_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean flcean re
