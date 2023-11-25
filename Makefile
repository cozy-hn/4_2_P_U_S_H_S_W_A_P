CC = gcc
WFLAG = -Wall -Wextra -Werror
RMF = rm -f

MAN_DIR = ./man/
MAN_BASE = push_swap ft_atoll ft_split list_utils parse_argv command_1 command_2 divide greedy get_cost \
	ft_printf/ft_printf ft_printf/ft_printf_util ft_printf/print_c ft_printf/print_d ft_printf/print_s \
	ft_printf/print_p ft_printf/print_u ft_printf/print_x
MAN_SRC = $(addprefix $(MAN_DIR), $(addsuffix .c, $(MAN_BASE)))
MAN_OBJ = $(addprefix $(MAN_DIR), $(addsuffix .o, $(MAN_BASE)))
MAN_NAME = push_swap

BON_DIR = ./bon/
BON_BASE = checker ft_atoll ft_split list_utils parse_argv command_1 command_2 \
	get_next_line_bonus/get_next_line get_next_line_bonus/get_next_line_utils
BON_SRC = $(addprefix $(BON_DIR), $(addsuffix _bonus.c, $(BON_BASE)))
BON_OBJ = $(addprefix $(BON_DIR), $(addsuffix _bonus.o, $(BON_BASE)))
BON_NAME = checker

all : $(MAN_NAME)

$(MAN_NAME) : $(MAN_OBJ)
	$(CC) $(WFLAG) $^ -o $@

bonus : $(BON_OBJ)
	$(CC) $(WFLAG) $^ -o $(BON_NAME)
	@touch bonus

%.o : %.c
	$(CC) $(WFLAG) -I $(dir $<) -c $< -o $@

clean :
	$(RMF) $(MAN_OBJ) $(BON_OBJ) bonus

fclean : clean
	$(RMF) $(MAN_NAME) $(BON_NAME)

re : clean all

.PHONY : all clean fclean re