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
    char **cmd = malloc(sizeof(char *) * 6);

    cmd[0] = "cd\0";
    cmd[1] = "setenv\0";
    cmd[2] = "unsetenv\0";
    cmd[3] = "env\0";
    cmd[4] = "exit\0";
    cmd[5] = NULL;
    return (cmd);
}

int check_command(char *arg)
{
    char **cmd = fill_cmd();

    for (int i = 0; cmd[i] != NULL; i++)
        if (my_strcmp(arg, cmd[i])) {
            free(cmd);
            return (i);
        }
    free(cmd);
    return (ERROR);
}
