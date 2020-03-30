##
## EPITECH PROJECT, 2019
## makefile
## File description:
## minishell
##

NAME	=	mysh

SRC	=	src/main.c \
		src/start.c \
		src/simple_cmd.c \
		src/my_putchar.c \
		src/my_putstr.c \
		src/dispatch_cmd.c \
		src/check_command.c \
		src/my_strlen.c \
		src/cd_f.c \
		src/my_split.c \
		src/count_space.c \
		src/env_f.c \
		src/clear_space.c \
		src/exe_bin.c \
		src/my_strcat.c \
		src/setenv_f.c \
		src/unsetenv_f.c \
		src/my_atoi.c \
		src/check_exe.c

CC	=	gcc

DEFLAGS	=	-W -Wextra -Wall -g3

CPPFLAGS	=	-I./include/

CFFLAGS	=	tests/unit_tests.c -I./include --coverage -lcriterion

OBJ	=	$(SRC:.c=.o)

all	:	$(OBJ)
		$(CC) $(DEFLAGS) -o $(NAME) $(OBJ) $(CPPFLAGS)

TU	:
		$(CC) -o unit_tests lib/my/*.c $(CFFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)
		rm -f *# \
		rm -f src/*# \
		rm -f include/*# \
		rm -f *~ \
		rm -f src/*~ \
		rm -f include/*~ \
		rm -f *.gcda \
		rm -f *.gcno

re	:	fclean all

.PHONY	:	all TU clean fclean re
