/*
** EPITECH PROJECT, 2020
** Minishell
** File description:
** exe bin
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "mysh.h"

static void fill_struct(mysh_t *m)
{
    m->bin->status = 0;
    m->bin->path_arg = my_getenv(m->envp, "PATH");
    m->bin->path = my_split(m->bin->path_arg, ':');
}

static int check_exist(char **paths)
{
    int nb = 0;
    int j = 0;

    for (j = 0; paths[j]; j++) {
        if ((nb = access(paths[j], F_OK)) != -1)
            break;
    }
    if (nb == -1)
        return (ERROR);
    else
        return (j);
}

static void free_bin(bin_t *bin)
{
    free(bin->path_arg);
    for (int i = 0; bin->path[i] != NULL; i++)
        free(bin->path[i]);
    free(bin->path);
}

int exe_bin(mysh_t *m)
{
    int j = 0;
    pid_t pid = 0;
    char *const *arg = m->arg;

    fill_struct(m);
    for (int i = 0; m->bin->path[i]; i++)
        m->bin->path[i] = my_strcat(m->bin->path[i], m->arg[0], '/');
    if ((j = check_exist(m->bin->path)) == ERROR) {
        my_putstr_error(m->arg[0]);
        my_putstr_error(CMDNTF);
        return (SUCCESS);
    }
    if ((pid = fork()) == 0)
        execve(m->bin->path[j], arg, m->envp);
    else {
        wait(&m->bin->status);
        check_sig(m->bin->status);
    }
    free_bin(m->bin);
    return (SUCCESS);
}
