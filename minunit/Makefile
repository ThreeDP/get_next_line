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
SRCS_TEST 		= 			$(wildcard ./*.c)
SRCS			=			$(wildcard $(DIR)*.c)
HEADERS 		= 			minunit.h
################ OTHERs		##################
BUF				=			5
F_BUFF			=			-D BUFFER_SIZE=$(BUF)
FLAGS 			=			-Wall -Werror -Wextra
################ RULES		##################

all: 		$(SRCS:.c=.o) $(SRCS_TEST:.c=.o)

%.o: 		%.c $(HEADERS)
	cc 			-o $@ -c $< $(FLAGS) $(F_BUFF)

$(SRCS_TEST:.c=.o):
	cc 			-o $@ -c $(@:.o=.c) $(FLAGS)
	gcc			$@ $(SRCS:.c=.o) $(FLAGS)
	@echo		"$(L_YELLOWB)"RUN TEST: $@ "$(L_WHITE)"
	@./a.out

norm:
	@cd 		$(DIR) && $(MAKE) $@

cleann:
	@rm 		-f $(SRCS_TEST:.c=.o)
	@rm		-f $(SRCS:.c=.o)
	

clean:		cleann
	@cd 		$(DIR) && $(MAKE) $@


fclean: 	cleann
	@rm 		-f run.exec
	@cd 		$(DIR) && $(MAKE) $@

re: fclean all
