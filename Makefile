NAME = so_long

SRCS =	so_long.c check_map.c error418.c read_map.c check_play.c check_map_too.c \
		open_natang.c dern.c check_dern.c render_game.c render_game_too.c

RED=\033[0;31;41m
GREEN=\033[0;32m
YEL=\033[0;37;47m
CYA=\033[1;36m
RESET=\033[0m

LIB_DIR = libft/
LIB = $(LIB_DIR)/libft.a

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)

DEL = rm -rf

%o: %c 
	@echo "$(RED).....................$(YEL).....................$(RESET)\n"
	@$(CC) $(CFLAG) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJS) mlxnaa
	@make -C $(LIB_DIR)
	@$(CC) $(CFLAGS) $(LIB) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)
	# @$(CC) $(CFLAGS) $(LIB) -o $(NAME) $(OBJS)

clean:
	@make -C $(LIB_DIR) clean
	@make -C ./mlx clean
	@$(DEL) $(OBJS)

fclean: clean
	# @say -v Kyoko "ちょっと待って、掃除中"
	@make -C $(LIB_DIR) fclean
	@$(DEL) $(NAME)
	# @cat pic/
	# @say -v Kyoko "お待たせしました"

mlxnaa:
	@printf "$(GREEN)"
	make -C ./mlx 2> /dev/null

re: fclean all

norm:
	# @cat pic/
	# @say -v Kanya "ขอตรวจ"
	# @say -v Kyoko "norminetto"
	# @say -v Kanya "หน่อยนะ"
	@echo "---- NORMINETTE ----"
	@norminette -R CheckDefine *.h
	@norminette -R CheckForbiddenSourceHeader *.c
	# @say -v Kanya "ขอบคุณที่รอ"
	@echo "---- THANK YOU ^w^Y ----"

.PHONY: norm clean fclean mlxnaa all re