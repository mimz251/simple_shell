#ifndef _SHELL_H_
#define _SHELL_H_

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define max_command_length 200

extern char **environ;

/* cd.c */
char *command = NULL;
size_t bufsize;
char *arg = token;
char *token = strtok(command, " ");
char *cmd = token;
char *prev_dir = getenv("OLDPWD");
char *getcwd(char *buf, size_t size);
/* cmd.c */
int main(int ac, char *av[]);

/* comment.c */
char *command;
size_t bufsize;
char *comment_pos = strchr();
int status = system();

/* delim.c */


/* execve.c */
pid_t pid;
char *av[];
int val = execve(av[0], av, NULL);

/* exit.c  */
char command[max_command_length];

/* logic_op.c */
int execute_command(char *);
char *command;
size_t bufsize;
char* token = strtok();
int result(); 

/* path.c */
struct PathNode{char *directory, struct PathNode *next}
void free_path_list(struct PathNode* head)
 char* path_env = getenv();
struct PathNode *head;
struct PathNode *tail;
char *path_copy = strdup(path_env);
struct PathNode *new_node();
struct PathNode *current;
char *path_token = strtok();

/* ppid.c */
pid_t pid;
pid_t ppid;

/* print_env.c */
char* command = NULL;
size_t bufsize = 0;
char **env_var = environ;
int status = system(command);
/* read.c */

/* separator.c */
void execute_command(const char* command);
int status = system();
char *command = NULL;
size_t bufsize;
char* token = strtok();

/* stat.c */
void sfile(char const filename[]);
ssize_t read;
char *buffer =;
size_t buf_size;
int s = open(buffer,O_RDONLY);

/* wait.c */
pid_t pid;

/* var_rep.c */

void replace_variables(char *command, int exit_status, int pid);
char *token = strtok();
char *command;
size_t bufsize;
int status = 0;
int exit_status = WEXITSTATUS();

/* strcspn.c */

/* strtok.c */

#endif
