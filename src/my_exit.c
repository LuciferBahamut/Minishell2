/*
** EPITECH PROJECT, 2020
** Minishell
** File description:
** my_exit
*/

#include <stdlib.h>
#include "mysh.h"

void my_exit(mysh_t *m)
{
    multi_free(m);
    my_putstr(EXIT);
    exit(SUCCESS);
}
