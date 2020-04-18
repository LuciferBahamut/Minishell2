/*
** EPITECH PROJECT, 2020
** Minishell
** File description:
** handle sig
*/

#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "mysh.h"

int check_sig(int status)
{
    if (WIFSIGNALED(status)) {
        if (SIGFPE == status && WCOREDUMP(status)) {
            my_putstr_error(SEGFAULTF2);
            my_putstr_error(SEGFAULTF3);
            return (SUCCESS);
        }
        if (WCOREDUMP(status) == 11) {
            my_putstr_error(SEGFAULT);
            return (SUCCESS);
        }
        if (SIGFPE == status) {
            my_putstr_error(SEGFAULTF);
            return (SUCCESS);
        }
    }
    return (SUCCESS);
}
