/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:57:13 by klino-an          #+#    #+#             */
/*   Updated: 2025/03/10 11:57:20 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>

bool	isalph(char str)
{
	if ((str >= 'A' && str <= 'Z')
		|| (str >= 'a' && str <= 'z')
		|| (str >= '0' && str <= '9'))
		return (true);
	else
		return (false);
}

bool	isup(char str)
{
	if (str >= 'A' && str <= 'Z')
		return (true);
	else
		return (false);
}

bool	islow(char str)
{
	if (str >= 'a' && str <= 'z')
		return (true);
	else
		return (false);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (isalph(str[i]))
		{
			if (islow(str[i]))
			{
				str[i] -= 32;
			}
			i++;
			while (isalph(str[i]))
			{
				if (isup(str[i]))
					str[i] += 32;
				i++;
			}
		}
		i++;
	}
	return (str);
}

int main()
{
   char str[] = "oi, tudo bem? 42palavras quarenta-e-duas;cinquenta+e+um";
 ft_strcapitalize(str);
 printf("%s \n",str); 
}
