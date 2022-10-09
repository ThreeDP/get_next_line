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
SRCS 			= 			$(wildcard ./*.c)
HEADERS 		= 			minunit.h
FLAGS 			= 			-Wall -Werror -Wextra
################ RULES		##################

all: 		$(SRCS:.c=.o)

%.o: 		%.c $(HEADERS) 
	@cd 		$(DIR) && $(MAKE)
	cc 			-o $@ -c $(@:.o=.c) $(FLAGS)
	gcc			$@ $(addprefix $(DIR), get_next_line.o) $(FLAGS)
	@echo		"$(L_YELLOWB)"RUN TEST: $@ "$(L_WHITE)"
	@./a.out

norm:
	@cd 		$(DIR) && $(MAKE) $@

cleann:
	@rm 		-f tests_libft.o
	@rm			-f $(SRCS:.c=.o)
	

clean:		cleann
	@cd 		$(DIR) && $(MAKE) $@


fclean: 	cleann
	@rm 		-f run.exec
	@cd 		$(DIR) && $(MAKE) $@

re: fclean all
