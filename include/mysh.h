/*
** EPITECH PROJECT, 2020
** header
** File description:
** header
*/

#ifndef MY_SH_ // MY_SH_ //
#define MY_SH_

////////////
// Return //
////////////

#define SUCCESS 0
#define ERROR 84
#define TRUE 1
#define FALSE 0

////////////
// Prompt //
////////////

#define RES "\e[0;0m"
#define RED "\e[3;1;5;31m"
#define CYAN "\e[1;36m"
#define GR "\e[1;32m"
#define BLUE "\e[1;34m"
#define YE "\e[1;33m"
#define CMD BLUE"₪"YE"["RED"CMD"RES YE"]"BLUE"₪ "GR"→ "RES

////////////
// String //
////////////

#define CMDNTF ": Command not found.\n"
// exit //
#define EXIT "exit\n"
// cd //
#define CDER "cd: Too many arguments.\n"
#define PERMDEN ": Permission denied.\n"
#define NAD ": Not a directory.\n"
#define NSFOD ": No such file or directory.\n"
// setenv //
#define SETER "setenv: Too many arguments.\n"
#define SETER2 "setenv: Variable name must begin with a letter.\n"
#define SETER3 "setenv: Variable name must contain alphanumeric characters.\n"
// unsetenv //
#define USETER "unsetenv: Too few arguments.\n"
// segfault //
#define SEGFAULT "Segmentation fault (core dumped)\n"
#define SEGFAULTF "Floating exeption (coredumped)\n"
#define SEGFAULTF2 "Segmentation fault (core dumped) && Floating Point"
#define SEGFAULTF3 "Floating exeption.\n"

///////////////
// Structure //
///////////////

typedef struct bin_s
{
    char *path_arg;
    char **copy_path;
    char **path;
    int status;
} bin_t;

typedef struct mysh_s
{
    char **arg;
    char **envp;
    char *buff;
    int cmd;
    int semi_colon;
    int pipe;
    bin_t *bin;
} mysh_t;

//////////////////
// Fonction SRC //
//////////////////

int start(char **envp, mysh_t *m);
void multi_free(mysh_t *m);
int run_shell(mysh_t *m);
char *clear_space(char *bf);
int check_command(char *arg);
void my_exit(mysh_t *m);
void my_env(mysh_t *m);
int my_setenv(mysh_t *m);
int my_unsetenv(mysh_t *m);
void my_cd(mysh_t *m);
int exe_bin(mysh_t *m);
char **fill_env(char **env, int nb);
char *my_getenv(char **envp, char *path);
int check_sig(int status);
void check_semicolon(mysh_t *m);
void handling_semicolon(mysh_t *m);
void exe_without_path(mysh_t *m);
void exe_with_path(mysh_t *m, int j);
int check_arg(char *arg);

////////////////////
// Fonction UTILS //
////////////////////

// putchar //
void my_putchar(char c);
void my_putchar_error(char c);
// putstr //
int my_putstr(char const *str);
int my_putstr_error(char const *str);
// strlen //
int my_strlen(char const *str);
// split //
char **my_split(char *src, char c);
int check_space(char *src, char c);
// strcmp //
int my_strcmp(char const *str1, char const *str2);
// strcat //
char *my_strcat(char *dest, char *src, char c);

#endif // MY_SH_ //
