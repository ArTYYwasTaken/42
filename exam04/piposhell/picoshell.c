#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

int    picoshell(char **cmds[])
{
    int    fd_in = 0;
    int    pipefd[2];
    int    i = 0;
    int    ret = 0;
    pid_t  pid;

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

int    count_cmds(int argc, char **argv)
{
    int    count = 1;
    for (int i = 1; i < argc; i++)
        if (strcmp(argv[i], "|") == 0)
            count++;
    return count;
}

int    main(int argc, char **argv)
{
    int    cmds_nbr = count_cmds(argc, argv);
    char    ***cmds = calloc(cmds_nbr + 1, sizeof(char **));

    if (!cmds)
        return 1;
    int    index = 0;
    int    start = 1;
    for (int i = 1; i <= argc; i++)
    {
        if (i == argc || strcmp(argv[i], "|") == 0)
        {
            cmds[index] = calloc(i - start + 1, sizeof(char *));
            if (!cmds[index])
                return 1;
            for (int j = 0; j < i - start; j++)
                cmds[index][j] = argv[start + j];
            index++;
            start = i + 1;
        }
    }
    int    ret = picoshell(cmds);
    for (int i = 0; i < cmds_nbr; i++)
        free(cmds[i]);
    free(cmds);
    return ret;
}
