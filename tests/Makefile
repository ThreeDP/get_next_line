################  COLORS	######################
L_RED			=			\033[0;31m
L_REDB			=			\033[1;31m
L_WHITE			=			\033[0;37m
L_WHITEB		=			\033[1;37m
L_YELLOW		=			\033[0;33m
L_YELLOWB		=			\033[1;33m
L_GREEN			=			\033[0;32m
L_GREENB		=			\033[1;32m
################ CONFIG	TESTS_MANDATORY	##################
DIR				=			../srcs/
DIR_MANDATORY_OUTS		=	./outs/mandatory/
DIR_BONUS_OUTS	=			./outs/bonus/
EXEC_MANDATORY_OUTS		=			$(wildcard $(DIR_MANDATORY_OUTS)*)
EXEC_BONUS_OUTS		=			$(wildcard $(DIR_BONUS_OUTS)*)
# Add your files with the function you can test
MANDATORY		=			$(addprefix $(DIR), get_next_line.c get_next_line_utils.c)
BONUS			=			$(addprefix $(DIR), get_next_line_bonus.c get_next_line_utils_bonus.c)
# Add your test names without .c
TESTS_MANDATORY	=			get_next_line_test
TESTS_BONUS		=			get_next_line_bonus_test
HEADERS_TEST 	= 			minunit.h
################ CONFIG YOUR PROJECT #############
FLAGS 			= 			-Wall -Werror -Wextra
################ RULES		######################

all: 		$(TESTS_MANDATORY) $(EXEC_MANDATORY_OUTS)
	@echo "$(L_WHITEB)$(EXEC_MANDATORY_OUTS)$(L_WHITE)"

bonus:		$(TESTS_BONUS) $(EXEC_BONUS_OUTS)
	@echo "$(L_WHITEB)$(EXEC_BONUS_OUTS)$(L_WHITE)"

$(TESTS_MANDATORY): $(HEADERS)
	$(CC)	-g $(FLAGS) -D BUFFER_SIZE=$(BUFFER) $(addsuffix .c, $@) $(MANDATORY) -o $(addprefix $(DIR_MANDATORY_OUTS), $@)

$(TESTS_BONUS): $(HEADERS)
	$(CC)	-g $(FLAGS) -D BUFFER_SIZE=$(BUFFER) $(addsuffix .c, $@) $(BONUS) -o $(addprefix $(DIR_BONUS_OUTS), $@)

$(EXEC_MANDATORY_OUTS):
	@echo  "$(L_YELLOWB)$@:$(L_WHITE) " && valgrind -q $@

$(EXEC_BONUS_OUTS):
	@echo  "$(L_YELLOWB)$@:$(L_WHITE) " && valgrind -q $@

clean:
	@rm			-f $(SRCS:.c=.o)
	@cd 		$(DIR) && $(MAKE) $@

fclean:			clean
	@rm 		-f $(EXEC_OUTS)
	@cd 		$(DIR) && $(MAKE) $@

re: fclean all

.PHONY: re fclean clean all $(TESTS_MANDATORY) $(EXEC_MANDATORY_OUTS) $(EXEC_BONUS_OUTS)