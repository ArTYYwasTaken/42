#include <stdio.h>

int base_conv(const char *str)
{
	int i = 0;
	while (str)
	{
		if (str[i] >= 0 && str[i] <= 9)
			return (str[i] + 10);
		if (str[i] >= 'a' && str[i] <= 'z')
			return (str[i] - 'a' + 10);
		if (str[i] >= 'A' && str[i] <= 'Z')
			return (str[i] - 'A' + 10);
		i++;
	}
	return 0;
}

int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int sign = 1;
	int result;
	if (str_base < 2 || str_base > 16)
		return (0);
	
	while (str[i])
	{
		if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign *= -1;
		}
		i++;
	}
	result = base_conv(str) * str_base + result;
	return (result * sign);
}
int		main(void)
{
	printf("%d\n", ft_atoi_base("011", 2));
	printf("%d\n", ft_atoi_base("16", 8));
	printf("%d\n", ft_atoi_base("123", 10));
	printf("%d\n", ft_atoi_base("FF", 16));
}