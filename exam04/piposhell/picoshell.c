#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int    picoshell(char **cmds[])
{
    int    fd_in = 0;
    int    pipefd[2];
    int    i = 0;
    int    ret = 0;
    pid_t    pid;

    while (cmds[i])
    {
        if (cmds[i + 1] && pipe(pipefd) < 0)
            return 1;
        pid = fork();
        if (pid == -1)
        {
            ret = 1;
            if (cmds[i + 1])
            {
                close(pipefd[0]);
                close(pipefd[1]);
            }
            break;
        }
        if (pid == 0)
        {
            if (fd_in != 0)
            {
                dup2(fd_in, 0);
                close(fd_in);
            }
            if (cmds[i + 1])
            {
                close(pipefd[0]);
                dup2(pipefd[1], 1);
                close(pipefd[1]);
            }
            execvp(cmds[i][0], cmds[i]);
            exit(1);
        }
        if (fd_in != 0)
            close(fd_in);
        if (cmds[i + 1])
        {
            close(pipefd[1]);
            fd_in = pipefd[0];
        }
        i++;
    }
    if (fd_in != 0)
        close(fd_in);
    while (wait(NULL) != -1)
        ;
    return ret;
}
