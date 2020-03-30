/*
** EPITECH PROJECT, 2020
** dispatch_cmd.c
** File description:
** minishell 1
*/

#include "my.h"

void exit_f(void)
{
    my_putstr(EXIT);
    exit(SUCCESS);
}

void display_error(char *str)
{
    my_putstr_error(str);
    my_putstr_error(": ");
    my_putstr_error(CMDNF);
}

void dispatch_cmd(mshel_s *ms)
{
    switch (ms->re) {
    case 0 : cd_f(ms);
        break;
    case 1 : setenv_f(ms);
        break;
    case 2 : unsetenv_f(ms);
        break;
    case 3 : env_f(ms);
        break;
    case 4 : exit_f();
        break;
    case 5 : exe_bin(ms);
        break;
    }
}
