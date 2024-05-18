SRC=$(shell find ./src -name \*.c -type f -print)
OBJ=$(patsubst ./src/%.c,./obj/%.o,$(SRC))
NAME=cub3d
FLAGS=-Wall -Werror -Wextra
LIBS=./libft/libft.a -I./libft ./mlx/libmlx.a -I./mlx -lm

all:
	make -C libft
	make -C mlx
	mkdir -p $(shell dirname $(OBJ))
	make $(NAME)

obj/%.o: src/%.c
	cc -c $(FLAGS) -g -o $@ $<

$(NAME): $(OBJ)
	cc $(FLAGS) $(OBJ) $(LIBS) -g -o $@

clean:
	make clean -C libft
	make clean -C mlx
	find ./obj -name \*.o -type f -delete

fclean: clean
	make fclean -C libft
	make clean -C mlx
	rm $(NAME)

re: clean all

.PHONY: all clean fclean re
