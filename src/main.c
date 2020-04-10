/*
** EPITECH PROJECT, 2020
** Minishell
** File description:
** Main
*/

#include <unistd.h>
#include "mysh.h"

int main(int ac, char **av, char **envp)
{
    mysh_t m;

    if (ac != 1 || envp == NULL || av == NULL)
        return (ERROR);
    start(envp, &m);
    return (SUCCESS);
}
