D_SRC = ./src/
SRC = main.c parsing/parsing_map.c parsing/parsing1.c parsing/gnl.c parsing/parsing2.c parsing/utils.c utils.c

D_OBJ = ./obj/
OBJ = $(addprefix $(D_OBJ), $(patsubst %.c,%.o,$(SRC)))

D_INC = ./inc/
S_INC = cube3d.h
INC = $(addprefix $(D_INC), $(S_INC))

CC = cc
FLAGS = -Wall -Wextra -Werror

NAME = cube3d

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
