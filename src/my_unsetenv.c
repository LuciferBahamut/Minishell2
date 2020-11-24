/*
** EPITECH PROJECT, 2020
** Minishell
** File description:
** unsetenv
*/

#include <stdlib.h>
#include "mysh.h"

static char **dell_elem(char **envp, int temp, int nb)
{
    int j = 0;

    envp[temp] = NULL;
    for (j = temp; j != nb - 1; j++)
        envp[j] = envp[j + 1];
    envp[j] = NULL;
    return (envp);
}

static int dell_env(mysh_t *m, int nb)
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
    if (temp == -1)
        return (SUCCESS);
    else
        m->envp = dell_elem(envp, temp, nb);
    return (SUCCESS);
}

int my_unsetenv(mysh_t *m)
{
    int space = check_space(m->buff, ' ');
    int nb = 0;

    space--;
    if (space == 0)
        my_putstr_error(USETER);
    else {
        for (int i = 0; m->envp[i] != NULL; i++, nb++);
        dell_env(m, nb);
    }
    return (SUCCESS);
}
