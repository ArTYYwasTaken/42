/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:38:55 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/17 15:06:09 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_length(int n)
{
	size_t	i;
	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_putnbr_str(int n, char *str, size_t *i)
{
	if (n >= 10)
		ft_putnbr_str(n / 10, str, i);
	str[(*i)++] = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	i;
	size_t	len;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = num_length(n);
	result = malloc((len + 1) * sizeof(char));
	if(!result)
		return (NULL);
	if (n < 0)
	{
		result[i++] = '-';
		n *= -1;
	}
	ft_putnbr_str(n, result, &i);
	result[i] = '\0';
	return (result);
}
/* 
// TEST CODE
int main()
{
    int test_values[] = {0, 123, -123, 2147483647, -2147483648};
    size_t num_tests = sizeof(test_values) / sizeof(test_values[0]);

    for (size_t i = 0; i < num_tests; i++)
	{
        char *result = ft_itoa(test_values[i]);
        if (result)
		{
            printf("\nft_itoa(%d) = %s\n", test_values[i], result);
            free(result);
        } else
            printf("ft_itoa(%d) failed to allocate memory\n", test_values[i]);
    }
	printf("\n");
    return 0;
}
 */