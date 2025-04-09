/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:44:23 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:44:23 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	size_t i;
	size_t start;
	size_t end;
	char *ptr;
	
	if(!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while(s1[start] && ft_strrchr(set, s1[start]))
		start++;
	while (end > start && ft_strrchr(set, s1[end - 1]))
		end--;
	ptr = malloc((end - start + 1) * sizeof(char));
	if(!ptr)
		return (NULL);	
	i = 0;
	while(start < end)
	{
		ptr[i] = s1[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}