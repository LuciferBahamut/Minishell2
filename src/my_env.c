/*
** EPITECH PROJECT, 2020
** Minishell
** File description:
** env
*/

#include <stdlib.h>
#include "mysh.h"

void my_env(mysh_t *m)
{
    for (int i = 0; m->envp[i] != NULL; i++) {
        my_putstr(m->envp[i]);
        my_putchar('\n');
    }
}
