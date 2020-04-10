##
## EPITECH PROJECT, 2020
## Minishell
## File description:
## Makefile
##

NAME    =       mysh

SRC     =	src/main.c		\
		src/start.c		\
		src/run_shell.c 	\
		src/clear_space.c	\
		src/check_command.c	\
		src/my_exit.c		\
		src/my_env.c		\
		src/my_setenv.c		\
		src/my_cd.c		\
		src/my_unsetenv.c	\
		src/exe_bin.c		\
		src/my_getenv.c		\
		src/handle_sig.c	\
		$(wildcard utils/*.c)

CC      =       gcc

CFLAGS 	=       -W -Wextra -Wall

CPPFLAGS        =       -I./include/

CFFLAGS =       tests/unit_tests.c -I./include --coverage -lcriterion

OBJ     =       $(SRC:.c=.o)

all     :       $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(CPPFLAGS)

debug   :       CFLAGS += -g3
debug   :       re

tests_run       :
		$(CC) -o unit_tests lib/my/*.c $(CFFLAGS)

clean   :
		rm -f $(OBJ)

fclean  :       clean
		rm -f $(NAME)
		rm -f *#		\
		rm -f src/*#		\
		rm -f include/*#        \
		rm -f *~                \
		rm -f src/*~            \
		rm -f include/*~        \
		rm -f *.gcda            \
		rm -f *.gcno

re      :       fclean all

.PHONY  :       all debug tests_run clean fclean re
