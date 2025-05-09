/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:51:22 by kemontei          #+#    #+#             */
/*   Updated: 2025/03/10 15:51:23 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		first_word;

	i = 0;
	first_word = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (first_word)
				str[i] -= 32;
			first_word = 0;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
			if (!first_word)
				str[i] += 32;
		else
			first_word = 0;
		else if (str[i] >= '0' && str[i] <= '9')
			first_word = 0;
		else
			first_word = 1;
		i++;
	}
	return (str);
}
/* int main()
{
	char str[] = "salut, comment tu vaS ? 42mots quarante-deux; cinquante+et+un";

	printf("%s\n", ft_strcapitalize(str));
	return 0;
} */