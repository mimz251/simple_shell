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





/* cmd.c */
/* comment.c */
/* delim.c */
/* env_environ.c  */
/* execve.c */
/* exit.c  */
/* logic_op.c */
/* path.c */
/* ppid.c */
/* print_env.c */
/* read.c */
/* separator.c */
/* stat.c */
/* wait.c */
/* var_rep.c */
/* strcspn.c */
/* strtok.c */
#endif
