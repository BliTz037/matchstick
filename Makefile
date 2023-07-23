##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## The supreme makefile
##

## Colors

NO_COLOR=\x1b[0m

OK_COLOR=\x1b[32;01m

ERROR_COLOR=\x1b[31;01m

WARN_COLOR=\x1b[33;01m

OK_STRING=$(OK_COLOR)[OK]$(NO_COLOR)

ERROR_STRING=$(ERROR_COLOR)[ERRORS]$(NO_COLOR)

WARN_STRING=$(WARN_COLOR)[WARNINGS]$(NO_COLOR)

##

SRC	=	src/main.c \
		src/matchstick.c \
		src/game_board.c \
		src/interaction.c \
		src/ia.c \
		src/error.c \
		src/my_putstr.c \
		src/my_putchar.c \
		src/my_strlen.c \
		src/my_getnbr.c \
		src/my_put_nbr.c \
		src/str_isnum.c

SRC_test =	src/matchstick.c \
			src/game_board.c \
			src/interaction.c \
			src/ia.c \
			src/error.c \
			src/my_putstr.c \
			src/my_putchar.c \
			src/my_strlen.c \
			src/my_getnbr.c \
			src/my_put_nbr.c \
			src/str_isnum.c

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

CFLAGS		+=	-Wall -Wextra -I./include/

all:	$(NAME)

$(NAME):	$(OBJ)
	@echo -e "building ... ${OK_STRING}"
	gcc -o $(NAME) $(OBJ)

tests_run:
	gcc -o unit_tests $(SRC_test) tests/*.c --coverage -lcriterion -I./include/
	./unit_tests

clean:
	rm -f $(OBJ)
	rm -f *.gcda
	rm -f *.gcno
	@echo -e "removing object files... ${WARN_STRING}"

fclean:	clean
	rm -f $(NAME)
	rm -f unit_tests
	@echo -e "removing binaries... ${WARN_STRING}"

re:	fclean	all
	@echo -e "removing and rebuilding... ${WARN_STRING}"

