/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbento-c <dbento-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:19:08 by dbento-c          #+#    #+#             */
/*   Updated: 2025/03/17 04:41:53 by dbento-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (0);
}
/*int main(void)
{
    char a1[] = "JAdo";

    printf("Antes: %s\n", a1);
    ft_strlowcase(a1);
    printf("Depois: %s\n", a1);
}*/
