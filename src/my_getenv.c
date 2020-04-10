/*
** EPITECH PROJECT, 2020
** Minishell
** File description:
** my_getenv
*/

#include <stdlib.h>
#include "mysh.h"

static int check_path(char *envp, char *path)
{
    for (int i = 0; path[i] != '\0';  i++)
        if (path[i] != envp[i])
            return (ERROR);
        else
            if (path[i + 1] == '\0')
                return (SUCCESS);
    return (SUCCESS);
}

char *my_getenv(char **envp, char *path)
{
    char *str;
    int k = 0;

    for(int i = 0; envp[i] != NULL; i++)
        if (check_path(envp[i], path) == SUCCESS) {
            str = malloc((my_strlen(envp[i]) + 1) * sizeof(char));
            for(int j = 5; envp[i][j] != '\0'; j++, k++)
                str[k] = envp[i][j];
        }
    str[k] = '\0';
    return (str);
}
