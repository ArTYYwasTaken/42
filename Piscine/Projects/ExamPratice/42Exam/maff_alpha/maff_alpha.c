#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int main()
{
	char c;

	c = 'a';

	while (c <= 'z')
	{
		if (c % 2 == 0)
		{
			ft_putchar(c - 32);
		}
		else
			ft_putchar(c);
		c++;
	}
	return 0;
}