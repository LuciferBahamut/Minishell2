/*
** EPITECH PROJECT, 2020
** clear space & tab
** File description:
** minishell1
*/

#include "my.h"

int find_char(char *buffer, int i)
{
    int nb = i;

    for (; buffer[i] != '\0'; i++) {
        if (buffer[i] != ' ' && buffer[i] != '\t') {
            nb = i;
            break;
        }
    }
    return (nb);
}

char *clear_space(char *bf)
{
    char *str = malloc(my_strlen(bf) * sizeof(char));

    for (int i = find_char(bf, 0), j = 0; bf[i] != '\0'; i++) {
        if (bf[i] == ' ' && (bf[i + 1] == ' ' || bf[i + 1] == '\t')) {
            str[j] = ' ';
            j++;
            i = find_char(bf, i);
            i--;
        }
        else if (bf[i] == '\t' && (bf[i + 1] == ' ' || bf[i + 1] == '\t')) {
            str[j] = ' ';
            j++;
            i = find_char(bf, i);
            i--;
        }
        else {
            str[j] = bf[i];
            j++;
        }
    }
    return (str);
}
