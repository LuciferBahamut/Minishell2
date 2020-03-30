/*
** EPITECH PROJECT, 2020
** unsetenv
** File description:
** minishell
*/

#include "my.h"

char **dell_env(char **envp, int temp, int nbr)
{
    int j = 0;

    envp[temp] = NULL;
    for (j = temp; j != nbr - 1; j++)
        envp[j] = envp[j + 1];
    envp[j] = NULL;
    return (envp);
}

int unsetenv_continue(mshel_s *ms, int nbr)
{
    char **envp = fill_env(ms->envp, envp, nbr);
    int temp = -1;

    for (int i = 0; i != nbr; i++)
        for (int j = 0; envp[i][j]; j++) {
            if (envp[i][j] != ms->arg[1][j])
                break;
            if (envp[i][j] == ms->arg[1][j] && envp[i][j + 1] == '=')
                temp = i;
        }
    if (temp == -1)
        return (SUCCESS);
    else {
        ms->envp = dell_env(envp, temp, nbr);
        return (SUCCESS);
    }
}

int unsetenv_f(mshel_s *ms)
{
    int space = check_space(ms->buffer);
    int nbr = 0;

    if (space > 1) {
        my_putstr(USETEER);
        return (SUCCESS);
    }
    else if (space == 0) {
        my_putstr(USETEER1);
        return (SUCCESS);
    }
    else {
        for (int i = 0; ms->envp[i]; i++)
            nbr++;
        unsetenv_continue(ms, nbr);
        return (SUCCESS);
    }
}
