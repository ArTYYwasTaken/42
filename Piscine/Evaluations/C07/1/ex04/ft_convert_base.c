/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:30:27 by migusant          #+#    #+#             */
/*   Updated: 2025/03/18 15:04:51 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_get_size_of_final_number(long number, int base);
int		ft_is_char_in_string(char ch, char *str);
int		ft_convert_str_to_long_int(char *str, char *base_from, int base);
int		ft_base_len(char *str);
int		ft_is_base_valid(char *base);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*ft_convert_to_base(long number, char *base_to, int base);

int	ft_base_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_is_base_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_base_len(base) <= 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	number;
	char	*result;

	if (!ft_is_base_valid(base_from) || !ft_is_base_valid(base_to))
		return (NULL);
	number = ft_convert_str_to_long_int(nbr, base_from, ft_base_len(base_from));
	if (number == -1)
		return (NULL);
	result = ft_convert_to_base(number, base_to, ft_base_len(base_to));
	return (result);
}

int	main()
{
	char	*res;
	char	*str;

	// Example 1: Converting from Binary to Decimal
	res = ft_convert_base("1010101", "01", "0123456789");
	printf("Binary 1010101 to Decimal: %s\n", res);
	printf("Expected output: 85\n");
	free(res);

	// Example 2: Converting from Hexadecimal to Binary
	res = ft_convert_base("2F", "0123456789ABCDEF", "01");
	printf("Hexadecimal 2F to Binary: %s\n", res);  
	printf("Expected output: 101111\n");
	free(res);

	// Example 3: Converting from Hexadecimal to Octal
	res = ft_convert_base("7F", "0123456789ABCDEF", "01234567");
	printf("Hexadecimal 7F to Octal: %s\n", res);
	printf("Expected output: 177\n");
	free(res);

	// Example 4: Converting from Octal to Decimal
	res = ft_convert_base("52", "01234567", "0123456789");
	printf("Octal 52 to Decimal: %s\n", res);
	printf("Expected output: 42\n");
	free(res);

	// Example 5: Converting from Decimal to Hexadecimal
	res = ft_convert_base("255", "0123456789", "0123456789ABCDEF");
	printf("Decimal 255 to Hexadecimal: %s\n", res);
	printf("Expected output: FF\n");
	free(res);

	// Example 6: Converting from Decimal to Custom Base
	res = ft_convert_base("42", "0123456789", "ponyt");
	printf("Decimal 42 to Custom base \"ponyt\": %s\n", res);
	printf("Expected output: oyn\n");
	free(res);

	// Example 7: Converting from Custom Base to Decimal
	res = ft_convert_base("oyn", "ponyt", "0123456789");
	printf("Custom base \"ponyt\" oyn to Decimal: %s\n", res);  
	printf("Expected output: 42\n");
	free(res);

	// Example 8: Converting a Negative Decimal Number to Binary
	res = ft_convert_base("-42", "0123456789", "01");
	printf("Negative Decimal -42 to Binary: %s\n", res);  
	printf("Expected output: -101010\n");
	free(res);

	// Example 9: Converting from Decimal to Base with One Character
	res = ft_convert_base("42", "0123456789", "1");
	printf("Decimal 42 to Invalid Base '1': %s\n", res);  
	printf("Expected output: NULL (invalid base)\n");
	free(res);

	// Example 10: Converting a Non-Numeric String (Invalid Input)
	res = ft_convert_base("hello", "0123456789", "0123456789");
	printf("Non-numeric string \"hello\" to Decimal: %s\n", res);  
	printf("Expected output: NULL (invalid string)\n");
	free(res);

	// Example 11: Converting Large Numbers
	res = ft_convert_base("2147483647", "0123456789", "01");
	printf("Decimal 2147483647 to Binary: %s\n", res);  
	printf("Expected output: 1111111111111111111111111111111\n");
	free(res);

	res = ft_convert_base("-2147483648", "0123456789", "01");
	printf("Decimal -2147483648 to Binary: %s\n", res);  
	printf("Expected output: -10000000000000000000000000000000\n");
	free(res);

	// Example 12: Converting from Base 36 to Decimal
	str = "0123456789abcdefghijklmnopqrstuvwxyz";
	res = ft_convert_base("z", str, "0123456789");
	printf("Base 36 'z' to Decimal: %s\n", res);
	printf("Expected output: 35\n");
	free(res);

	// Example 13: Converting from Base `!@#` to Decimal
	res = ft_convert_base("@#", "!@#", "0123456789");
	printf("Base !@# @# to Decimal: %s\n", res);
	printf("Expected output: 5\n");
	free(res);

	// Example 14: Converting from Base `!#$%` to Binary
	res = ft_convert_base("$%", "!#$%", "01");
	printf("Base !#$%% $%% to Binary: %s\n", res);  
	printf("Expected output: 1011\n");
	free(res);

	// Example 15: Converting from Decimal to Base `*&^`
	res = ft_convert_base("255", "0123456789", "*&^");
	printf("Decimal 255 to Base *&^: %s\n", res);
	printf("Expected output: &**&&*\n");
	free(res);

	// Example 16: Converting from Base `!#$%` to Base `*&^`
	res = ft_convert_base("$%", "!#$%", "*&^");
	printf("Base !#$%% $%% to Base *&^: %s\n", res);
	printf("Expected output: &*^\n");
	free(res);

	// Example 17: Converting from Decimal to Base `!@#`
	res = ft_convert_base("42", "0123456789", "!@#");
	printf("Decimal 42 to Base !@#: %s\n", res);  
	printf("Expected output: @@#!\n");
	free(res);

	// Example 18: Converting from Base `*&^` to Decimal
	res = ft_convert_base("^*&", "*&^", "0123456789");
	printf("Base *&^ ^*& to Decimal: %s\n", res);  
	printf("Expected output: 19\n");
	free(res);

	// Example 19: Converting from Base `!@#` to Base `*&^`
	res = ft_convert_base("@#", "!@#", "*&^");
	printf("Base !@# @# to Base *&^: %s\n", res);  
	printf("Expected output: &^\n");
	free(res);

	// Example 20: Converting a Negative Number from Base `!@#` to Decimal
	res = ft_convert_base("-@#", "!@#", "0123456789");
	printf("Negative Base !@# -@# to Decimal: %s\n", res);
	printf("Expected output: -5\n");
	free(res);

	// Example 21: Invalid Base - Base `!` (Only one character)
	res = ft_convert_base("42", "!", "0123456789");
	printf("Base ! to Decimal: %s\n", res);  
	printf("Expected output: NULL (invalid base)\n");
	free(res);

	// Example 22: Converting a Non-Numeric String to Base `!@#`
	res = ft_convert_base("hello", "0123456789", "!@#");
	printf("Non-numeric string \"hello\" to Base !@#: %s\n", res);  
	printf("Expected output: NULL (invalid string)\n");
	free(res);

	return 0;
}
