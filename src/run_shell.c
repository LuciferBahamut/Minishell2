/*
** EPITECH PROJECT, 2020
** Minishell
** File description:
** Run shell
*/

#include <stdio.h>
#include <unistd.h>
#include "mysh.h"

static void dispatch_cmd(mysh_t *m)
{
    switch (m->cmd) {
    case 0 : my_cd(m);
        break;
    case 1 : my_setenv(m);
        break;
    case 2 : my_unsetenv(m);
        break;
    case 3 : my_env(m);
        break;
    case 4 : my_exit(m);
        break;
    case ERROR : exe_bin(m);
        break;
    }
}

static int check_buf(char *buffer)
{
    int nbr = 0;
    int i = 0;

    for (i = 0; buffer[i] != '\n'; i++)
        if (buffer[i] == ' ' || buffer[i] == '\t')
            nbr++;
    if (nbr == i)
        return (ERROR);
    else
        return (SUCCESS);
}

static void compute_line(mysh_t *m)
{
    int i = 0;

    m->buff = clear_space(m->buff);
    for (i = 0; m->buff[i] != '\n'; i++);
    m->buff[i] = '\0';
    if (m->buff[i - 1] == ' ' || m->buff[i - 1] == '\t')
        m->buff[i - 1] = '\0';
    m->arg = my_split(m->buff, ' ');
    m->cmd = check_command(m->arg[0]);
    dispatch_cmd(m);
}

int run_shell(mysh_t *m)
{
    size_t size = 100;

    while (1) {
        my_putstr(CMD);
        if (getline(&m->buff, &size, stdin) == EOF)
            return (ERROR);
        break;
    }
    if (check_buf(m->buff) == ERROR)
        run_shell(m);
    else {
        compute_line(m);
        run_shell(m);
    }
    return (SUCCESS);
}
