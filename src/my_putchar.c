/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** printf
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putchar_error(char c)
{
    write(2, &c, 1);
}
