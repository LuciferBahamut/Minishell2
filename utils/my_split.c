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

static char **my_split_alloc(char *src, char **str, char c)
{
    int i = 0;
    int k = 0;

    for (int j = 0; src[i] != '\0'; i++, k++) {
        if (src[i] == c) {
            str[j] = malloc(sizeof(char) * (k + 1));
            k = 0;
            j++;
        }
        else if (src[i + 1] == '\0') {
            str[j] = malloc(sizeof(char) * (k + 2));
            k = 0;
            break;
        }
    }
    return (str);
}

char **my_split(char *src, char c)
{
    int nb = check_space(src, c);
    char **str = malloc((nb + 1) * sizeof(char *));
    int k = 0;

    str = my_split_alloc(src, str, c);
    for (int i = 0, j = 0; src[i] != '\0'; i++, k++) {
        if (src[i] == c) {
            str[j][k] = '\0';
            j++;
            i++;
            k = 0;
        }
        else if (src[i + 1] == '\0') {
            str[j][k] = src[i];
            str[j][k + 1] = '\0';
            break;
        }
        str[j][k] = src[i];
    }
    str[nb] = NULL;
    return (str);
}
