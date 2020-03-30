/*
** EPITECH PROJECT, 2020
** check_command
** File description:
** minishell 1
*/

#include "my.h"

char **fill_cmd(char **cmd)
{
    cmd = malloc(sizeof(char *) * 5);
    cmd[0] = malloc(sizeof(char) * 2 + 1);
    cmd[0] = "cd";
    cmd[1] = malloc(sizeof(char) * 6 + 1);
    cmd[1] = "setenv";
    cmd[2] = malloc(sizeof(char) * 8 + 1);
    cmd[2] = "unsetenv";
    cmd[3] = malloc(sizeof(char) * 3 + 1);
    cmd[3] = "env";
    cmd[4] = malloc(sizeof(char) * 4 + 1);
    cmd[4] = "exit";
    return (cmd);
}

int check_command(char *arg)
{
    char **cmd = fill_cmd(cmd);
    int i = 0;

    for (int j = 0; i != 5; i++) {
        while (arg[j] != '\0' || arg[j] != ' ') {
            if (cmd[i][j] != arg[j])
                break;
            else if (cmd[i][j] == arg[j] && arg[j + 1] == '\0') {
                free(cmd);
                return (i);
            }
            else
                j++;
        }
        j = 0;
    }
    free(cmd);
    return (i);
}
