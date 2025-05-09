#include <stdio.h>

int ft_value_of(char c)
{
	if (c >= '0' && c<= '9')
		return (c - '0');
	if (c >= 'a' && c<= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c<= 'F')
		return (c - 'A' + 10);
	return (-1);
}

int ft_isvalid(char c, int base)
{
	int value;
	value = ft_value_of(c);
	return (value >= 0 && value <= base);
}

int ft_atoi_base(char *str, int str_base)
{
	int i = 0;
	int sign = 1;
	int result;

	if (str_base < 2 || str_base > 16)
		return 0;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && ft_isvalid(str[i], str_base))
	{
		result = result * str_base + ft_value_of(str[i]);
		i++;
	}

	return (result * sign);
}
int main()
{
	int base = 2;
	char str[] = "101010";
	printf("%d\n", ft_atoi_base(str, base));
	return 0;
}