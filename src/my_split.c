/*
** EPITECH PROJECT, 2019
** split
** File description:
** project
*/

#include "my.h"

char **my_split(char *src)
{
    char **str = malloc((check_space(src) + 1) * sizeof(char *));
    int i = 0;
    int k = 0;

    for (int j = 0; src[i] != '\0'; i++) {
        if (src[i] == ' ')
            j++;
        str[j] = malloc(i + 1);
    }
    i = 0;
    for (int j = 0; src[i] != '\0'; i++, k++) {
        if (src[i] == ' ') {
            str[j][i] = '\0';
            j++;
            i++;
            k = 0;
        }
        str[j][k] = src[i];
    }
    return (str);
}

char **my_split_path(char *src)
{
    char **str = malloc((check_space(src) + 1) * sizeof(char *));
    int i = 0;
    int k = 0;

    for (int j = 0; src[i] != '\0'; i++) {
        if (src[i] == ':')
            j++;
        str[j] = malloc(i + 1);
    }
    i = 0;
    for (int j = 0; src[i] != '\0'; i++, k++) {
        if (src[i] == ':') {
            str[j][i] = '\0';
            j++;
            i++;
            k = 0;
        }
        str[j][k] = src[i];
    }
    return (str);
}
