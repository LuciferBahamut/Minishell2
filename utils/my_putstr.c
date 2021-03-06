/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** printf
*/

#include "mysh.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}

int my_putstr_error(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar_error(str[i]);
    return (0);
}
