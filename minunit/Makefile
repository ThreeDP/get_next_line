################  COLORS	##################
L_RED			=			'\033[0;31m'
L_REDB			=			'\033[1;31m'
L_WHITE			=			'\033[0;37m'
L_WHITEB		=			'\033[1;37m'
L_YELLOW		=			'\033[0;33m'
L_YELLOWB		=			'\033[1;33m'
L_GREEN			=			'\033[0;32m'
L_GREENB		=			'\033[1;32m'
################ CONFIG		##################
DIR 			= 			../srcs/
M_SRCS			=			get_next_line.c get_next_line_utils.c
B_SRCS			=			get_next_line_bonus.c get_next_line_utils_bonus.c
HEADERS 		= 			minunit.h
################ OTHERs		##################
F_BUFF			=			-D BUFFER_SIZE=
FLAGS 			=			-Wall -Werror -Wextra
################ RULES		##################

all:		m b

m:
	gcc		get_next_line_test.c $(addprefix $(DIR), $(M_SRCS)) $(FLAGS) $(F_BUFF)1
	@echo		"$(L_YELLOWB)"RUN TEST BUFFER: 1 "$(L_WHITE)"
	@./a.out
	gcc		get_next_line_test.c $(addprefix $(DIR), $(M_SRCS)) $(FLAGS) $(F_BUFF)42
	@echo		"$(L_YELLOWB)"RUN TEST BUFFER: 42 "$(L_WHITE)"
	@./a.out
	gcc		get_next_line_test.c $(addprefix $(DIR), $(M_SRCS)) $(FLAGS) $(F_BUFF)1000
	@echo		"$(L_YELLOWB)"RUN TEST BUFFER: 1000 "$(L_WHITE)"
	@./a.out

b:
	gcc		get_next_line_bonus_test.c $(addprefix $(DIR), $(B_SRCS)) $(FLAGS) $(F_BUFF)1
	@echo		"$(L_YELLOWB)"RUN TEST BUFFER: 1 "$(L_WHITE)"
	@./a.out
	gcc		get_next_line_bonus_test.c $(addprefix $(DIR), $(B_SRCS)) $(FLAGS) $(F_BUFF)42
	@echo		"$(L_YELLOWB)"RUN TEST BUFFER: 42 "$(L_WHITE)"
	@./a.out
	gcc		get_next_line_bonus_test.c $(addprefix $(DIR), $(B_SRCS)) $(FLAGS) $(F_BUFF)1000
	@echo		"$(L_YELLOWB)"RUN TEST BUFFER: 1000 "$(L_WHITE)"
	@./a.out

norm:
	@cd 		$(DIR) && $(MAKE) $@

cleann:
	@rm 		-f $(SRCS_TEST:.c=.o)
	@rm		-f $(SRCS:.c=.o)
	
clean:		cleann
	@cd 		$(DIR) && $(MAKE) $@

fclean: 	cleann
	@rm 		-f a.out
	@cd 		$(DIR) && $(MAKE) $@

re: fclean all
