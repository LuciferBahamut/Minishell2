/*
** EPITECH PROJECT, 2020
** cd
** File description:
** minishell1
*/

#include "my.h"

int count_slash(char *path)
{
    int nb = 0;

    for (int i = 0; path[i]; i++)
        if (path[i] == '/')
            nb++;
    nb--;
    return (nb);
}

int return_home(mshel_s *ms)
{
    char *path = my_getenv_path(ms->envp, "PWD");
    int nb = count_slash(path);

    for (int i = 0; i != nb; i ++)
        chdir("../");
    return (SUCCESS);
}

int cd_f(mshel_s *ms)
{
    int space = check_space(ms->buffer);

    if (space == 0)
        return_home(ms);
    else if (space >= 2) {
        my_putstr(CDER);
        return (SUCCESS);
    }
    else
        if (chdir(ms->arg[1]) == -1) {
            perror(ms->arg[1]);
            return (SUCCESS);
        }
}
