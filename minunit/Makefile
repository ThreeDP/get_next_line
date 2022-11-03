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
BUF			=			1
F_BUFF			=			-D BUFFER_SIZE=$(BUF)
FLAGS 			=			-Wall -Werror -Wextra
################ RULES		##################

all:		$(SRCS_TEST:.c=.o)
       
%.o:	%.c	$(HEADERS)
	gcc		$< $(SRCS) $(FLAGS) $(F_BUFF)
	@echo		"$(L_YELLOWB)"RUN TEST: $< "$(L_WHITE)"
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

fill:	$(HEADERS)
	gcc		fill_list_test_1.c $(SRCS) $(FLAGS) -D BUFFER_SIZE=1
	@echo		"$(L_YELLOWB)"RUN TEST: $< "$(L_WHITE)"
	@./a.out
	gcc		fill_list_test_42.c $(SRCS) $(FLAGS) -D BUFFER_SIZE=42
	@echo		"$(L_YELLOWB)"RUN TEST: $< "$(L_WHITE)"
	@./a.out
	gcc		fill_list_test_1_milion.c $(SRCS) $(FLAGS) -D BUFFER_SIZE=100000000
	@echo		"$(L_YELLOWB)"RUN TEST: $< "$(L_WHITE)"
	@./a.out

check:	$(HEADERS)
	gcc		check_static_test_1.c $(SRCS) $(FLAGS) -D BUFFER_SIZE=1
	@echo		"$(L_YELLOWB)"RUN TEST: $< "$(L_WHITE)"
	@./a.out
	gcc		check_static_test_42.c $(SRCS) $(FLAGS) -D BUFFER_SIZE=42
	@echo		"$(L_YELLOWB)"RUN TEST: $< "$(L_WHITE)"
	@./a.out
	gcc		check_static_test_1_milion.c $(SRCS) $(FLAGS) -D BUFFER_SIZE=100000000
	@echo		"$(L_YELLOWB)"RUN TEST: $< "$(L_WHITE)"
	@./a.out