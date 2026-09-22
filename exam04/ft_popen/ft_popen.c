#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int ft_popen(const char *file, char *const argv[], char type)
{
	int		fd[2];
	pid_t	pid;

	if (!file || !file[0] || !argv || (type != 'r' && type != 'w'))
		return -1;
	if (pipe(fd) < 0)
		return -1;
	pid = fork();
	if (pid < 0)
	{
		close(fd[0]);
		close(fd[1]);
		return -1;
	}
	if (pid == 0)						/* ---- child ---- */
	{
		if (type == 'r')
			dup2(fd[1], STDOUT_FILENO);	/* stdout -> pipe write end */
		else
			dup2(fd[0], STDIN_FILENO);	/* stdin  <- pipe read end  */
		close(fd[0]);
		close(fd[1]);
		execvp(file, argv);				/* returns only on failure */
		exit(1);
	}
	/* ---- parent ---- */
	if (type == 'r')
	{
		close(fd[1]);					/* parent never writes */
		return fd[0];
	}
	close(fd[0]);						/* parent never reads  */
	return fd[1];
}

int main(void)
{
	int		fd;
	char	buffer[1024];
	ssize_t	n;

	fd = ft_popen("ls", (char *const[]){"ls", NULL}, 'r');
	while ((n = read(fd, buffer, sizeof(buffer))) > 0)
		write(STDOUT_FILENO, buffer, n);
	close(fd);
	return (0);
}
