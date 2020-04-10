/*
** EPITECH PROJECT, 2020
** Minishell
** File description:
** check command
*/

#include <stdlib.h>
#include "mysh.h"

static char **fill_cmd(void)
{
    char **cmd = malloc(sizeof(char *) * 5);

    cmd[0] = "cd";
    cmd[1] = "setenv";
    cmd[2] = "unsetenv";
    cmd[3] = "env";
    cmd[4] = "exit";
    return (cmd);
}

int check_command(char *arg)
{
    char **cmd = fill_cmd();

    for (int i = 0; i != 5; i++)
        if (my_strcmp(arg, cmd[i]) == TRUE) {
            free(cmd);
            return (i);
        }
    free(cmd);
    return (ERROR);
}
