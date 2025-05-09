/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:49:29 by migusant          #+#    #+#             */
/*   Updated: 2025/03/15 17:38:54 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*str_dest;

	i = 0;
	while (src[i] != '\0')
		i++;
	str_dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!str_dest)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		str_dest[i] = src[i];
		i++;
	}
	str_dest[i] = '\0';
	return (str_dest);
}

/* int	main()
{
	char	*str_src;
	char	*str_dest;
	str_src = "This string will be copied!";
	str_dest = ft_strdup(str_src);
	printf("str_dest[] = %s\n", str_dest);
	free(str_dest);
	return 0;
} */
