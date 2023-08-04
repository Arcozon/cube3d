D_SRC = ./src/
S_SRC = main.c parsing/parsing1.c parsing/gnl.c parsing/utils.c
SRC = src/main.c src/parsing/parsing1.c src/parsing/gnl.c src/parsing/utils.c

D_OBJ = ./obj/
OBJ = $(addprefix $(D_OBJ), $(S_SRC:.cpp=.o))

D_INC = ./inc/

CC = cc
FLAGS = -Wall -Wextra -Werror

NAME = cube3d

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o$@

$(OBJ): $(D_OBJ)%.o : $(D_SRC)%.c
	@mkdir -p $(D_OBJ)
	$(CC) $(FLAGS) -I$(D_INC) -c $< -o $@

clean:
	rm -rf $(D_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean flcean re
