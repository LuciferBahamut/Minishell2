/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** check arg setenv
*/

#include "mysh.h"

static int check_first_char(char c)
{
    int nb = 0;

    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        nb++;
    else if (c == '_')
        nb--;
    if (nb == 0)
        return (ERROR);
    return (SUCCESS);
}

static int check_next_char(char c)
{
    int nb = 0;

    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        nb++;
    else if (c == '_' || (c >= '0' && c <= '9'))
        nb--;
    if (nb == 0)
        return (ERROR);
    return (SUCCESS);
}

int check_arg(char *arg)
{
    if (check_first_char(arg[0]) == ERROR) {
        my_putstr_error(SETER2);
        return (ERROR);
    }
    for (int i = 1; arg[i] != '\0'; i++)
        if (check_next_char(arg[i]) == ERROR) {
            my_putstr_error(SETER3);
            return (ERROR);
        }
    return (SUCCESS);
}
