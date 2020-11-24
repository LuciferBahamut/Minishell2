/*
** EPITECH PROJECT, 2020
** Minishell
** File description:
** strcat
*/

#include <stdlib.h>
#include "mysh.h"

char *my_strcat(char *dest, char *src, char c)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *res = malloc((my_strlen(dest) + my_strlen(src) + 1) * sizeof(char));

    for (; dest[i] != '\0'; i++)
        res[i] = dest[i];
    if (dest[my_strlen(dest)] != c && src[0] != c) {
        res[my_strlen(dest)] = c;
        k++;
    }
    while (src[j]) {
        res[i + j + k] = src[j];
        j++;
    }
    res[i + j + k] = '\0';
    return (res);
}
