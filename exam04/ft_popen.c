#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int ft_popen(const char *file, char *const argv[], char type)
{
	int pid = -1;
	int fd[2];

	if (!file || !file[0])
		return -1;
	int pipecheck = pipe(fd);
	if (pipecheck < 0)
		return -1;
	pid = fork();
	if (pid < 0)
		return close(pid), -1;
	if (pid > 0)
	{
		if (type == 'r')
			dup2(fd[1], 1);
		else if (type == 'w')
			dup2(fd[0], 0);
		close(fd[0]), close(fd[1]);
		execvp(file, argv);
		exit(-1);
	}
	if (type == 'r')
		return (close(fd[1]), fd[0]);
	else if (type == 'w')
		return (close(fd[0]), fd[1]);
	return -1;
}

int main()
{
    int  fd;
	char buffer[1024];
    fd = ft_popen("ls", (char *const []){"ls", NULL}, 'w');
    while (read(fd, buffer, sizeof(buffer)) > 0)
        write(fd, buffer, sizeof(buffer));
    return (0);
}
