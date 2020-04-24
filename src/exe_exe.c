/*
** EPITECH PROJECT, 2020
** minishell 2
** File description:
** exe exe
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "mysh.h"

void exe_without_path(mysh_t *m)
{
    pid_t pid = 0;
    char *const *arg = m->arg;

    if ((pid = fork()) == 0)
        execve(m->arg[0], arg, m->envp);
    wait(&m->bin->status);
    check_sig(m->bin->status);
}

void exe_with_path(mysh_t *m, int j)
{
    pid_t pid = 0;
    char *const *arg = m->arg;

    if ((pid = fork()) == 0)
        execve(m->bin->path[j], arg, m->envp);
    wait(&m->bin->status);
    check_sig(m->bin->status);
}
