/*
** EPITECH PROJECT, 2020
** minishell 2
** File description:
** handling semi colon
*/

#include <stdlib.h>
#include "mysh.h"

static void dispatch_cmd(mysh_t *m)
{
    switch (m->cmd) {
    case 0 : my_cd(m);
        break;
    case 1 : my_setenv(m);
        break;
    case 2 : my_unsetenv(m);
        break;
    case 3 : my_env(m);
        break;
    case 4 : my_exit(m);
        break;
    case ERROR : exe_bin(m);
        break;
    }
}

static void reset_struct(mysh_t *m)
{
    m->cmd = 0;
    m->semi_colon = 0;
    m->pipe = 0;
}

static char *del_space(char *str)
{
    int max = my_strlen(str);

    str = clear_space(str);
    max = max - 1;
    if (str[max] == ' ' || str[max] == '\t')
        str[max] = '\0';
    return (str);
}

void handling_semicolon(mysh_t *m)
{
    char **split = my_split(m->buff, ';');

    for (int i = 0; split[i] != NULL; i++)
        split[i] = del_space(split[i]);
    for (int i = 0; split[i] != NULL; i++) {
        m->arg = my_split(split[i], ' ');
        m->cmd = check_command(m->arg[0]);
        dispatch_cmd(m);
    }
    reset_struct(m);
}
