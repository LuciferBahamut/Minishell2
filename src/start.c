/*
** EPITECH PROJECT, 2020
** Minishell
** File description:
** Start
*/

#include <stdlib.h>
#include "mysh.h"

void multi_free(mysh_t *m)
{
    for (int i = 0; m->envp[i] != NULL; i++)
        free(m->envp[i]);
    if (m->arg != NULL)
        for (int i = 0; m->arg[i] != NULL; i++)
            free(m->arg[i]);
    free(m->arg);
    free(m->envp);
    free(m->buff);
    free(m->bin);
    free(m);
}

static char **copy_env(char **envp)
{
    int k = 0;
    int i = 0;
    char **env;

    while (envp[k] != NULL)
        k++;
    env = malloc(sizeof(char *) * (k + 1));
    for (int j = 0; envp[j] != NULL; j++) {
        env[j] = malloc(sizeof(char) * my_strlen(envp[j]) + 1);
        for (i = 0; envp[j][i] != '\0'; i++)
            env[j][i] = envp[j][i];
        env[j][i] = '\0';
    }
    env[k] = NULL;
    return (env);
}

static void fill_struct(mysh_t *m, char **envp)
{
    m->envp = copy_env(envp);
    m->buff = malloc(sizeof(char) * 100);
    m->bin = malloc(sizeof(bin_t));
}

int start(char **envp, mysh_t *m)
{
    m = malloc(sizeof(mysh_t));
    fill_struct(m, envp);
    if (run_shell(m) == ERROR) {
        my_putstr(EXIT);
        multi_free(m);
        return (SUCCESS);
    }
    multi_free(m);
    return (SUCCESS);
}
