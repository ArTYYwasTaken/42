#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

int main(int argc, char *argv[])
{
	char *str = argv[1];
	int i = ft_strlen(str) - 1;
	int end;
	int start;
	
	if (argc == 2)
	{
		while (str[i] >= 0)
		{
			while (str[i] == ' ' || str[i] == '\t')
				i--;
			end = i;
			while (!(str[i] == ' ' || str[i] == '\t'))
				i--;
			start = i + 1;
			while (start <= end)
			{
				write(1, &str[start++], 1);
			}
			break;
			i--;
		}
	}
	write(1, "\n", 1);
	return 0;
}