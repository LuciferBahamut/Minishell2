/*
** EPITECH PROJECT, 2020
** Minishell
** File description:
** setenv
*/

#include <stdlib.h>
#include "mysh.h"

char **fill_env(char **env, int nb)
{
    char **envp = malloc(sizeof(char *) * (nb + 2));
    int j = 0;

    for (int i = 0; env[i] != NULL; i++) {
        envp[i] = malloc((my_strlen(env[i]) + 1) * sizeof(char));
        for (j = 0; env[i][j] != '\0'; j++)
            envp[i][j] = env[i][j];
        envp[i][j] = '\0';
    }
    envp[nb + 1] = NULL;
    return (envp);
}

static char **replace_env(mysh_t *m, char **envp, int temp, int space)
{
    if (space == 1)
        envp[temp] = my_strcat(m->arg[1], "\0", '=');
    else
        envp[temp] = my_strcat(m->arg[1], m->arg[2], '=');
    return (envp);
}

static char **add_env(mysh_t *m, int nb, int space)
{
    char **envp = fill_env(m->envp, nb);
    int temp = -1;

    for (int i = 0; i != nb; i++)
        for (int j = 0; envp[i][j] != '\0'; j++) {
            if (envp[i][j] != m->arg[1][j])
                break;
            if (envp[i][j] == m->arg[1][j] && envp[i][j + 1] == '=')
                temp = i;
        }
    if (temp == -1) {
        if (space == 1)
            envp[nb] = my_strcat(m->arg[1], "\0", '=');
        else
            envp[nb] = my_strcat(m->arg[1], m->arg[2], '=');
    }
    else
        envp = replace_env(m, envp, temp, space);
    return (envp);
}

int my_setenv(mysh_t *m)
{
    int space = check_space(m->buff, ' ');
    int nb = 0;

    space--;
    if (space == 0)
        my_env(m);
    else if (space >= 3 || check_arg(m->arg[1]) == ERROR) {
        if (space >= 3)
            my_putstr_error(SETER);
        else
            return (SUCCESS);
    }
    else {
        for (int i = 0; m->envp[i] != NULL; i++, nb++);
        m->envp = add_env(m, nb, space);
    }
    return (SUCCESS);
}
