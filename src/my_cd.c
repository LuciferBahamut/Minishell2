/*
** EPITECH PROJECT, 2020
** Minishell
** File description:
** my cd
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "mysh.h"

static int count_slash(char *path)
{
    int nb = 0;

    for (int i = 0; path[i] != '\0'; i++)
        if (path[i] == '/')
            nb++;
    nb--;
    return (nb);
}

static void go_home(mysh_t *m)
{
    char *path = my_getenv(m->envp, "PWD");
    int nb = count_slash(path);

    for (int i = 0; i != nb; i++)
        chdir("../");
    free(path);
}

static int compute_space(mysh_t *m)
{
    int space = check_space(m->buff, ' ');

    space--;
    if (m->semi_colon == 5) {
        space = 0;
        for (int i = 0; m->arg[i] != NULL; i++, space++);
    }
    return (space);
}

static void check_error_cd(char *str)
{
    if (errno == EACCES) {
        my_putstr_error(str);
        my_putstr_error(PERMDEN);
    }
    else if (errno == ENOTDIR) {
        my_putstr_error(str);
        my_putstr_error(NAD);
    }
    else
        if (errno == ENOENT) {
            my_putstr_error(str);
            my_putstr_error(NSFOD);
        }
}

void my_cd(mysh_t *m)
{
    int space = compute_space(m);

    if (space == 0)
        go_home(m);
    else if (space > 2)
        my_putstr_error(CDER);
    else
        if (chdir(m->arg[1]) == -1)
            check_error_cd(m->arg[1]);
}
