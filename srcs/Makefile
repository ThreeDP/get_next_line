################  COLORS	##################
L_RED			=			'\033[0;31m'
L_REDB			=			'\033[1;31m'
L_WHITE			=			'\033[0;37m'
L_WHITEB		=			'\033[1;37m'
L_YELLOW		=			'\033[0;33m'
L_YELLOWB		=			'\033[1;33m'
L_GREEN			=			'\033[0;32m'
L_GREENB		=			'\033[1;32m'
################ LIBRARY	##################
NAME 			= 			get_next_line
################ MANDATORY	##################
SRCS 			=			get_next_line.c 			get_next_line_utils.c
HEADER			=			get_next_line.h
################ BONUS  	##################
SRCS_BOUNS 		=			get_next_line_bonus.c		get_next_line_utils_bonus.c
HEADER_BONUS	=			get_next_line.h
################ OTHERs		##################
BUF				=			5
F_BUFF			=			-D BUFFER_SIZE=$(BUF)
FLAGS 			=			-Wall -Werror -Wextra
################ RULES		##################
all: 		$(NAME)

%.o: 		%.c
	gcc 			-o $@ -c $< $(FLAGS) $(F_BUFF)

$(NAME): 	$(SRCS:.c=.o)
	cc			-o $@ -c $(SRCS:.c=.o) $(FLAGS) $(F_BUFF)
	@echo		"$(L_YELLOWB) Mandatory Part... $(L_WHITE)"

norm:
	@echo		"$(L_YELLOWB) NORM executing... $(L_WHITE)"
	@norminette 	$(SRCS) $(HEADER)

clean:
	@rm -f 		$(SRCS:.c=.o)
	@echo		"$(L_YELLOWB) Objects Removed... $(L_WHITE)"

fclean: 	clean
	@rm -f 		$(NAME)
	@echo		"$(L_YELLOWB) Source Removed... $(L_WHITE)"

re: 		fclean all

.PHONY: 	all fclean clean re
