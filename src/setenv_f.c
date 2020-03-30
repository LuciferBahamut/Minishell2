/*
** EPITECH PROJECT, 2020
** setenv
** File description:
** minishell
*/

#include "my.h"

char **fill_env(char **str, char **envp, int nbr)
{
    envp = malloc(nbr + 1 * sizeof(char *));
    for (int i = 0; str[i]; i++) {
        envp[i] = malloc((my_strlen(str[i]) + 1) * sizeof(char));
        envp[i] = str[i];
    }
    return (envp);
}

char **replace_env(mshel_s *ms, char **envp, int i)
{
    if (check_space(ms->buffer) == 1) {
        envp[i] = my_strcat2(ms->arg[1], "\0");
        return (envp);
    }
    if (check_space(ms->buffer) == 2) {
        envp[i] = my_strcat2(ms->arg[1], ms->arg[2]);
        return (envp);
    }
    else if (my_atoi(ms->arg[3]) == 0)
        return (ms->envp);
    else {
        envp[i] = my_strcat2(ms->arg[1], ms->arg[2]);
        return (envp);
    }
}

char **setenv_f_b(mshel_s *ms, int nbr, int space)
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
    if (temp == -1) {
        if (space == 1)
            envp[nbr] = my_strcat2(ms->arg[1], "\0");
        else
            envp[nbr] = my_strcat2(ms->arg[1], ms->arg[2]);
    }
    else
        envp = replace_env(ms, envp, temp);
    return (envp);
}

int setenv_f(mshel_s *ms)
{
    int space = check_space(ms->buffer);
    int nbr = 0;

    if (space == 0) {
        env_f(ms);
        return (SUCCESS);
    }
    else if (space > 3) {
        my_putstr_error(SETEER);
        return (SUCCESS);
    }
    else {
        for (int i = 0; ms->envp[i]; i++)
            nbr++;
        ms->envp = setenv_f_b(ms, nbr, space);
    }
}
