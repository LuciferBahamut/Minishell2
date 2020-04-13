/*
** EPITECH PROJECT, 2020
** Minishell
** File description:
** my_split
*/

#include <stdlib.h>
#include "mysh.h"

int check_space(char *buffer, char c)
{
    int nb = 0;

    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == c)
            nb++;
    nb++;
    return (nb);
}

char **my_split(char *src, char c)
{
    char **str = malloc(((check_space(src, c)) + 1) * sizeof(char *));
    int i = 0;
    int k = 0;

    for (int j = 0; src[i] != '\0'; i++) {
        if (src[i] == c)
            j++;
        str[j] = malloc(i + 1);
    }
    i = 0;
    for (int j = 0; src[i] != '\0'; i++, k++) {
        if (src[i] == c) {
            str[j][k] = '\0';
            j++;
            i++;
            k = 0;
        }
        str[j][k] = src[i];
    }
    str[check_space(src, c)] = NULL;
    return (str);
}
