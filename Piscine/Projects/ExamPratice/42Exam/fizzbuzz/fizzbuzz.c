#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int num)
{
	if (num > 9)
	{
		ft_putnbr(num / 10);
	}
	char c = num % 10 + 48;
	ft_putchar(c);
}

int main()
{
	int num;

	num = 1;
	while (num <= 100)
	{
		if (num % 15 == 0)
			write(1, "fizzbuzz", 8);
		else if (num % 5 == 0)
			write(1 , "buzz", 4);
		else if (num % 3 == 0)
			write(1, "fizz", 4);
		else
		ft_putnbr(num);
		num++;
		write(1, "\n", 1);
	}
}