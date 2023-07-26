#ifndef _SHELL_H_
#define _SHELL_H_

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define max_command_length 200
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1


extern char **environ;

/* cd.c */
char command[max_command_length];
sstream ss;
const char *prev_dir = getenv();
char current_dir[max_command_length];
char prev_dir[max_command_length];
int status = system(command);

/* cmd.c */
int main(int ac, char *av[]);

/* comment.c */
char command[max_command_length];
char *comment_pos = strchr();
 int status = system(command);

/* delim.c */

/* env_environ.c  */
int main(int ac, char *av[], char *env[];

/* execve.c */
pid_t pid;
char *av[];
int val = execve(av[0], av, NULL);

/* exit.c  */
char command[max_command_length];
int status = system(command);

/* logic_op.c */
char command[1000];
sstream ss;
char *token = strtok();
int status = system(token);

/* path.c */
 DIR *directory;
 struct dirent *entry;

/* ppid.c */
pid_t pid;
pid_t ppid;

/* print_env.c */
void print_environment(void);
char command[1000];
int status = system(command);
sstream ss;

/* read.c */

/* separator.c */
char command[1000];
char *token = strtok();
sstream ss;
int status = system(token);

/* stat.c */
void sfile(char const filename[]);
ssize_t read;
char *buffer =;
size_t buf_size;
int s = open(buffer,O_RDONLY);

/* wait.c */
pid_t pid;

/* var_rep.c */
void replace_variables(char *command);
char command[max_command_length];
char* token = strtok();
replace_variables(command);
int status = system(command);
void sfile(char const filename[]);
struct stat sfile;

/* strcspn.c */

/* strtok.c */

#endif
