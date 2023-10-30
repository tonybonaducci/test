CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L ./minilibx-linux -lm -lmlx -Ilmlx -lXext -lX11
RM = rm -f

NAME = fractol

SRC = main.c render.c init.c events.c math_fun.c tricorn.c string_utils.c error_helper.c

OBJ = $(SRC:.c=.o)

all: deps $(NAME)

deps:
	$(MAKE) -C ./minilibx-linux

$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) -o $(NAME)

clean:
	$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)

download:
	@wget https://cdn.intra.42.fr/document/document/21300/minilibx-linux.tgz
	@tar -xzf minilibx-linux.tgz
	@rm minilibx-linux.tgz

re: fclean all