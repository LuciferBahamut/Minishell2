/*
** EPITECH PROJECT, 2020
** exe bin
** File description:
** minishell
*/

#include "my.h"

char *my_getenv_path(char **envp, char *path)
{
    char *str;

    for (int i = 0; envp[i]; i++)
        if (check_path(envp[i], path) == SUCCESS) {
            str = malloc(my_strlen(envp[i]) + 1 * sizeof(char));
            for (int j = 5, k = 0; envp[i][j] != '\0'; j++, k++)
                str[k] = envp[i][j];
        }
    return (str);
}

int check_sig(int status)
{
    if (WIFSIGNALED(status)) {
        if (SIGFPE == status && WCOREDUMP(status)) {
            my_putstr_error(SEGFAULTF2);
            my_putstr_error(SEGFAULTF3);
            return (SUCCESS);
        }
        if (WCOREDUMP(status)) {
            my_putstr_error(SEGFAULT);
            return (SUCCESS);
        }
        if (SIGFPE == status) {
            my_putstr_error(SEGFAULTF);
            return (SUCCESS);
        }
    }
}

int exe_bin(mshel_s *ms)
{
    char *path = my_getenv_path(ms->envp, "PATH");
    char **paths = my_split_path(path);
    int j = 0;
    pid_t pid = 0;
    char *const *arg = ms->arg;

    check_alias(ms);
    for (int i = 0; paths[i]; i++)
        paths[i] = my_strcat(paths[i], ms->arg[0]);
    if ((j = check_exist(paths, j)) == ERROR) {
        display_error(ms->arg[0]);
        return (SUCCESS);
    }
    if ((pid = fork()) == 0)
        execve(paths[j], arg, ms->envp);
    else {
        wait(&ms->status);
        check_sig(ms->status);
        free(path);
    }
    return (SUCCESS);
}
