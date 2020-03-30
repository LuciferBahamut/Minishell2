/*
** EPITECH PROJECT, 2020
** simple_cmd
** File description:
** minishell
*/

#include "my.h"

static int check_buf(char *buffer)
{
    int nbr = 0;
    int i = 0;

    for (i = 0; buffer[i] != '\n'; i++)
        if (buffer[i] == ' ' || buffer[i] == '\t')
            nbr++;
    if (nbr == i)
        return (ERROR);
    else
        return (SUCCESS);
}

int cmd_continue(mshel_s *ms, char *buffer)
{
    ms->buffer = clear_space(buffer);
    for (int i = 0; ms->buffer[i] != '\0'; i++)
        if (ms->buffer[i] == '\n')
            ms->buffer[i] = '\0';
    ms->arg = my_split(ms->buffer);
    ms->re = check_command(ms->arg[0]);
    dispatch_cmd(ms);
}

int simple_cmd(mshel_s *ms)
{
    char *buffer = ms->buffer;
    size_t size = 100;

    while (1) {
        my_putstr(CMD);
        if (getline(&buffer, &size, stdin) == EOF) {
            my_putstr(EXIT);
            return (CEOF);
        }
        break;
    }
    if (check_buf(buffer) == ERROR)
        simple_cmd(ms);
    else {
        cmd_continue(ms, buffer);
        simple_cmd(ms);
    }
    return (SUCCESS);
}
