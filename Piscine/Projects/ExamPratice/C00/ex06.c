#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_comb2(void)
{
	int n1;
	int n2;

	n1 = 0;
	while (n1 < n2)
	{
		ft_putchar(n1 / 10);
		ft_putchar(n1 % 10);
		ft_putchar(' ');
		ft_putchar(n2 / 10);
		ft_putchar(n2 % 10);
		while (n1 <= 98 && n2 <= 99)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		n2++;
	}
	
}