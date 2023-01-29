NAME = so_long

SRCS = so_long.c

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)

DEL = rm -rf

all: $(NAME)
	
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	$(DEL) $(OBJS)

fclean: clean
	# @say -v Kyoko "ちょっと待って、掃除中"
	$(DEL) $(NAME)
	# @cat pic/
	# @say -v Kyoko "お待たせしました"

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

.PHONY: norm clean fclean all re