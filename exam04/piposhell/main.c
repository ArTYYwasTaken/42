#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int    picoshell(char **cmds[]);

static int    count_cmds(int argc, char **argv)
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
