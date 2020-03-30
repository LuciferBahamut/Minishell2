/*
** EPITECH PROJECT, 2020
** check exe
** File description:
** minishell
*/

#include "my.h"

int check_path(char *envp, char *path)
{
    for (int i = 0; path[i] != '\0'; i++)
        if (path[i] != envp[i])
            return (ERROR);
        else
            if (path[i + 1] == '\0')
                return (SUCCESS);
}

void check_alias(mshel_s *ms)
{
    if (ms->arg[0][0] == 'l' && ms->arg[0][1] == 'l') {
        ms->arg[0] = "ls";
        ms->arg[1] = "-l";
    }
}

int check_exist(char **paths, int j)
{
    int nbr = 0;

    for (j = 0; paths[j]; j++)
        nbr++;
    for (j = 0; paths[j]; j++)
        if (access(paths[j], F_OK) != -1)
            break;
    if (nbr == j)
        return (ERROR);
    else
        return (j);
}
