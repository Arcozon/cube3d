D_SRC = ./src/
SRC = parsing/parsing_l_map.c parsing/parsing1.c parsing/fixing_map.c parsing/gnl.c parsing/checking_map.c parsing/parsing2.c parsing/utils.c utils.c main.c

D_OBJ = ./obj/
OBJ = $(addprefix $(D_OBJ), $(patsubst %.c,%.o,$(SRC)))

D_INC = ./inc/
S_INC = cube3d.h
INC = $(addprefix $(D_INC), $(S_INC))

CC = cc
FLAGS = -Wall -Wextra -Werror -g

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
