/*
** EPITECH PROJECT, 2020
** start
** File description:
** project
*/

#include "my.h"

char **fill_senv(char **envp)
{
    int i = 0;
    char **str;

    while (envp[i])
        i++;
    str = malloc(sizeof(char *) * i);
    for (int j = 0; envp[j]; j++) {
        str[j] = malloc((my_strlen(envp[j]) + 1) * sizeof(char));
        for (int k = 0; envp[j][k] != '\0'; k++)
            str[j][k] = envp[j][k];
    }
    return (str);
}

void fill_struct(mshel_s *ms, char **envp)
{
    ms->buffer = malloc((100 + 1) * sizeof(char));
    ms->envp = fill_senv(envp);
    ms->status = 0;
}

int start(int ac, char **av, char **envp)
{
    mshel_s *ms = malloc(sizeof(mshel_s));

    if (ac != 1) {
        free(ms);
        exit(ERROR);
    }
    fill_struct(ms, envp);
    if (simple_cmd(ms) == CEOF)
        exit(SUCCESS);
    free(ms);
    return (SUCCESS);
}
