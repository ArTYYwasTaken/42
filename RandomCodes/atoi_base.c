#include <stdio.h>

int ft_value_of(char c) {
    if (c >= '0' && c <= '9')
        return (c - '0');
    else if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10);
    else if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10);
    return (-1);  // Invalid character
}

int ft_isvalid(char c, int base) {
    int value = ft_value_of(c);
    return (value >= 0 && value < base);  // Valid if within range
}

int ft_atoi_base(const char *str, int str_base) {
    if (str_base < 2 || str_base > 16) // Base must be between 2 and 16
        return (0);

    int result = 0;
    int sign = 1;
    int index = 0;

    // Skip whitespaces
    while (str[index] == ' ' || (str[index] >= 9 && str[index] <= 13))
        index++;

    // Handle sign
    if (str[index] == '-' || str[index] == '+') {
        if (str[index] == '-')
            sign = -1;
        index++;
    }

    // Convert valid digits
    while (str[index] != '\0' && ft_isvalid(str[index], str_base)) {
        result = result * str_base + ft_value_of(str[index]);
        index++;
    }

    return (result * sign);
}

int		main()
{
	printf("%d\n", ft_atoi_base("011", 2));
	printf("%d\n", ft_atoi_base("16", 8));
	printf("%d\n", ft_atoi_base("123", 10));
	printf("%d\n", ft_atoi_base("FF", 16));
}