/*
** EPITECH PROJECT, 2020
** env
** File description:
** minishell
*/

#include "my.h"

void env_f(mshel_s *ms)
{
    for (int i; ms->envp[i]; i++) {
        my_putstr(ms->envp[i]);
        my_putchar('\n');
    }
}
