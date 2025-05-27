/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:35:15 by kemontei          #+#    #+#             */
/*   Updated: 2025/05/27 16:33:52 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	check_conversions(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_printfchar(va_arg(args, int));
	else if (c == 's')
		count += ft_printfstring(va_arg(args, const char *));
	else if (c == 'd' || c == 'i')
		count += ft_printfdecimal(va_arg(args, int));
	else if (c == 'u')
		count += ft_printfunsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		count += ft_printfhex(va_arg(args, unsigned int), c);
	else if (c == 'p')
		count += ft_printfpointer(va_arg(args, void *));
	else if (c == '%')
		count += write(1, "%", 1);
	return (count);
}

static int	handle_regular_chars(const char *str, size_t *i)
{
	int	count;

	count = 0;
	while (str[*i] && str[*i] != '%')
	{
		write(1, &str[(*i)++], 1);
		count++;
	}
	return (count);
}

static int	handle_conversions(const char *str, va_list args, size_t *i)
{
	int	count;

	count = 0;
	if (str[*i + 1])
	{
		count += check_conversions(args, str[*i + 1]);
		*i += 2;
	}
	else
		(*i)++;
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	size_t	i;

	if (!str || (str[0] == '%' && str[1] == '\0'))
		return (-1);
	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		count += handle_regular_chars(str, &i);
		if (str[i] == '%')
			count += handle_conversions(str, args, &i);
	}
	va_end(args);
	return (count);
}
int	main()
{

	char c = 'A';
	char *str = "isso e uma string";
	unsigned int unb = 42;
	int nb = -42;

	printf("\ntexto normal:\n"); 
	int r1 = ft_printf("%s\n", str);
	printf("caracteres impressos: %d\n", r1);
	r1 = printf("%s\n", str);
	printf("caracteres impressos: %d\n", r1);
	   
	printf("\nstring:\n");
	int r2 = ft_printf("%s\n",str);
	printf("caracteres impressos: %d\n", r2);
	r2 = printf("%s\n",str);
	printf("caracteres impressos: %d\n", r2);


	printf("\nchar:\n");
	int r3 = ft_printf("%c%c%c\n",c, 'a', '3');
	printf("caracteres impressos: %d\n", r3);
	r3 = printf("%c%c%c\n",c, 'a', '3');
	printf("caracteres impressos: %d\n", r3);


	printf("\ndecimal:\n");
	int r4 = ft_printf("%d\n", nb);
	printf("caracteres impressos: %d\n", r4);
	r4 = printf("%d\n", nb);
	printf("caracteres impressos: %d\n", r4);

	printf("\ninteger:\n");
	int r5 = ft_printf("%i\n", nb);
	printf("caracteres impressos: %d\n", r5);
	r5 = printf("%i\n", nb);
	printf("caracteres impressos: %d\n", r5);

	printf("\nunsigned:\n");
	int r6 = ft_printf("%u\n", unb);
	printf("caracteres impressos: %d\n", r6);
	r6 = printf("%u\n", unb);
	printf("caracteres impressos: %d\n", r6);

	printf("\nlow hexadecimal:\n");
	int r7 = ft_printf("%x\n", nb);
	printf("caracteres impressos: %d\n", r7);
	r7 = printf("%x\n", nb);
	printf("caracteres impressos: %d\n", r7);

	printf("\nupper decimal:\n");
	int r8 = ft_printf("%X\n", nb);
	printf("caracteres impressos: %d\n", r8);
	r8 = printf("%X\n", nb);
	printf("caracteres impressos: %d\n", r8);

	printf("\npointer:\n");
	int r9 = ft_printf("%p\n", &str);
	printf("caracteres impressos: %d\n", r9);
	r9 = printf("%p\n", &str);
	printf("caracteres impressos: %d\n", r9);

	printf("\nteste %%:\n");
	int r10 = ft_printf("%%\n");
	printf("caracteres impressos: %d\n", r10);
	r10 = printf("%%\n");
	printf("caracteres impressos: %d\n", r10);
}