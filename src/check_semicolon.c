/*
** EPITECH PROJECT, 2020
** minishell 2
** File description:
** check semi colon
*/

#include "mysh.h"

static void check_pipe(mysh_t *m)
{
    int nb = 0;

    for (int i = 0; m->buff[i] != '\0'; i++)
        if (m->buff[i] == '|')
            nb++;
    if (nb != 0) {
        m->cmd = 6;
        m->pipe = 6;
    }
    else
        m->pipe = 0;
}

void check_semicolon(mysh_t *m)
{
    int nb = 0;

    for (int i = 0; m->buff[i] != '\0'; i++)
        if (m->buff[i] == ';')
            nb++;
    if (nb != 0) {
        m->cmd = 5;
        m->semi_colon = 5;
    }
    else
        m->semi_colon = 0;
    check_pipe(m);
}
