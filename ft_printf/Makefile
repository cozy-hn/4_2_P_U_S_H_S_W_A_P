CC = cc
CFLAGS = -Wall -Wextra -Werror
RMF = rm -f
SRC = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putunbr.c print_base16.c print_adress.c \
print_p.c print_s.c print_format.c 
OBJT = $(SRC:.c=.o)
NAME = libftprintf.a
AR = ar rcus

all: $(NAME)

$(NAME): $(OBJT)
	$(AR) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean:
	$(RMF) $(OBJT) $(BOBJT)

fclean: clean
	$(RMF) $(NAME)

re: fclean
	make

.PHONY : all clean fclean re