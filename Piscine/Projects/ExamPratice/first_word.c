#include <unistd.h>

int main(int argc, char *argv[])
{
	int i = 0;
	char *str = argv[1];
	if (argc != 2)
		return 0;
	while (str[i])
	{
		if ((str[i] >= 7 && str[i] <= 13) || str[i] == 32)
			i++;
		if ((str[i] >= 65 && str[i] <= 90)
			|| (str[i] >= 97 && str[i] <= 122))
			write(1, &str[i], 1);
		if ((str[i + 1] >= 7 && str[i + 1] <= 13) || str[i + 1] == 32)
			break;
		i++;
	}
	write(1, "\n", 1);
	return 0;
}