NAME = libftprintf.a
SRCS = 	ft_printf.c \
		ft_putnbr.c \
		ft_putstr.c 

GCC = gcc -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)

LIB = ar -crs

DEL = rm -rf

%o: %c 
	$(GCC) -c $< -o $@ 

all: $(NAME)
	
$(NAME): $(OBJS)
	$(LIB) $(NAME) $(OBJS)

clean:
	$(DEL) $(OBJS)

fclean: clean
	$(DEL) $(NAME) 

re: fclean all

.PHONY: bonus clean fclean all re