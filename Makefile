##
## EPITECH PROJECT, 2020
## Minishell
## File description:
## Makefile
##

NAME    =       mysh

SRC     =	src/main.c			\
		src/start.c			\
		src/run_shell.c 		\
		src/clear_space.c		\
		src/check_command.c		\
		src/my_exit.c			\
		src/my_env.c			\
		src/my_setenv.c			\
		src/my_cd.c			\
		src/my_unsetenv.c		\
		src/exe_bin.c			\
		src/my_getenv.c			\
		src/handle_sig.c		\
		src/check_semicolon.c		\
		src/handling_semicolon.c	\
		src/exe_exe.c			\
		$(wildcard utils/*.c)

CC      ?=       gcc

CFLAGS 	=       -W -Wextra -Wall

CPPFLAGS        =       -I./include/

OBJ     =       $(SRC:.c=.o)

name	:	all

all     :       $(OBJ)
		$(CC) -o $(NAME) $(OBJ)

debug   :       CFLAGS += -g3
debug   :       re

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

.PHONY  :       name all debug clean fclean re
