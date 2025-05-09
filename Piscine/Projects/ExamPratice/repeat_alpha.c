#include <unistd.h>

int	main(int argc, char **argv)
{
	int i = 0;
	int repeat;
	char *str = argv[1];

	if (argc == 2)
	{
		while (str[i] != '\0')
		{
			repeat = 1;
			if (str[i] >= 'A' && str[i] <= 'Z')
				repeat = str[i] - 64;
			if (str[i] >= 'a' && str[i] <= 'z')
				repeat = str[i] - 96;
			while (repeat >= 1)
			{
				write(1, &str[i], 1);
				repeat--;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}