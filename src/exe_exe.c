/*
** EPITECH PROJECT, 2020
** minishell 2
** File description:
** exe exe
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "mysh.h"

static int check_is_dir(char **arg)
{
    char **split = my_split(arg[0], '/');
    struct stat st;

    stat(split[1], &st);
    if (S_ISDIR(st.st_mode)) {
        my_putstr_error(arg[0]);
        my_putstr_error(PERMDEN);
        return (ERROR);
    }
    return (SUCCESS);
}

void exe_without_path(mysh_t *m)
{
    pid_t pid = 0;
    char *const *arg = m->arg;

    if (check_is_dir(m->arg) == ERROR)
        return;
    if (m->pipe == 6) {
        execve(m->arg[0], arg, m->envp);
        return;
    }
    else
        if ((pid = fork()) == 0)
            execve(m->arg[0], arg, m->envp);
    wait(&m->bin->status);
    check_sig(m->bin->status);
}

void exe_with_path(mysh_t *m, int j)
{
    pid_t pid = 0;
    char *const *arg = m->arg;

    if (check_is_dir(m->arg) == ERROR)
        return;
    if (m->pipe == 6) {
        execve(m->arg[0], arg, m->envp);
        return;
    }
    else
        if ((pid = fork()) == 0)
            execve(m->bin->path[j], arg, m->envp);
    wait(&m->bin->status);
    check_sig(m->bin->status);
}
