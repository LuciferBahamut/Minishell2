/*
** EPITECH PROJECT, 2020
** count space
** File description:
** minishell
*/

#include "my.h"

int check_space(char *buffer)
{
    int nb = 0;

    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == ' ')
            nb++;
    return (nb);
}

int check_double_point(char *buffer)
{
    int nb = 0;

    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == ':')
            nb++;
    return (nb);
}
