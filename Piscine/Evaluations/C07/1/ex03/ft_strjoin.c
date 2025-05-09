/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:24:41 by migusant          #+#    #+#             */
/*   Updated: 2025/03/18 11:56:05 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strslen(int size, char **strs, char *sep)
{
	int	i;
	int	strslen;
	int	strssep;

	i = 0;
	strslen = 0;
	strssep = 0;
	while (i < size)
	{
		strslen = strslen + ft_strlen(strs[i]);
		i++;
	}
	strssep = ft_strlen(sep) * (size - 1);
	return (strslen + strssep + 1);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		total_len;
	char	*str;

	if (size <= 0)
	{
		str = (char *)malloc(sizeof(char));
		*str = '\0';
		return (str);
	}
	total_len = ft_strslen(size, strs, sep);
	str = (char *)malloc(sizeof(char) * total_len);
	if (!str)
		return (NULL);
	str[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		if (i < size - 1)
			ft_strcat(str, sep);
		i++;
	}
	return (str);
}

/* int	main(void) 
{
	// Test Case 1: Empty strings array
	char *strs1[] = {};
	char *sep1 = ", ";
	char *result1 = ft_strjoin(0, strs1, sep1);
	printf("'%s' (Expected: '')\n", result1);
	free(result1);

	// Test Case 2: Single string
	char *strs2[] = {"Hello"};
	char *sep2 = ", ";
	char *result2 = ft_strjoin(1, strs2, sep2);
	printf("'%s' (Expected: 'Hello')\n", result2);
	free(result2);

	// Test Case 3: Multiple strings with separator
	char *strs3[] = {"Hello", "World", "Join"};
	char *sep3 = "-";
	char *result3 = ft_strjoin(3, strs3, sep3);
	printf("'%s' (Expected: 'Hello-World-Join')\n", result3);
	free(result3);

	// Test Case 4: Strings with a longer separator
	char *strs4[] = {"Apple", "Banana", "Cherry"};
	char *sep4 = " -> ";
	char *result4 = ft_strjoin(3, strs4, sep4);
	printf("'%s' (Expected: 'Apple -> Banana -> Cherry')\n", result4);
	free(result4);

	// Test Case 5: Empty strings but non-empty separator
	char *strs5[] = {"", "", ""};
	char *sep5 = ", ";
	char *result5 = ft_strjoin(3, strs5, sep5);
	printf("'%s' (Expected: ', , ')\n", result5);
	free(result5);

	// Test Case 6: Only separator, no actual strings
	char *strs6[] = {};
	char *sep6 = ",";
	char *result6 = ft_strjoin(0, strs6, sep6);
	printf("'%s' (Expected: '')\n", result6);
	free(result6);

	// Test Case 7: Strings without separator
	char *strs7[] = {"123", "456", "789"};
	char *sep7 = "";
	char *result7 = ft_strjoin(3, strs7, sep7);
	printf("'%s' (Expected: '123456789')\n", result7);
	free(result7);

	// Test Case 8: Large input with many strings
	char *strs8[] = {"One", "Two", "Three", "Four", "Five", 
			"Six", "Seven", "Eight", "Nine", "Ten"};
	char *sep8 = "|";
	char *result8 = ft_strjoin(10, strs8, sep8);
	printf("'%s' (Expected: 'One|Two|Three|...|Nine|Ten')\n", result8);
	free(result8);

	// Edge Case 1: All strings are empty (testing with separator)
	char *strs9[] = {"", "", ""};
	char *sep9 = ", ";
	char *result9 = ft_strjoin(3, strs9, sep9);
	printf("'%s' (Expected: ', , ')\n", result9);
	free(result9);

	// Edge Case 2: Large strings
	char *strs10[] = {"A very long string that goes on for",
				" a while to test large input."};
	char *sep10 = " ";
	char *result10 = ft_strjoin(1, strs10, sep10);
	printf("'%s' (Expected: 'A very long ... large input.')\n", result10);
	free(result10);

	// Edge Case 3: Separator is an empty string
	char *strs11[] = {"Apple", "Banana", "Cherry"};
	char *sep11 = "";
	char *result11 = ft_strjoin(3, strs11, sep11);
	printf("'%s' (Expected: 'AppleBananaCherry')\n", result11);
	free(result11);

	// Edge Case 4: One string with the separator (should not add separator)
	char *strs12[] = {"Hello"};
	char *sep12 = ", ";
	char *result12 = ft_strjoin(1, strs12, sep12);
	printf("'%s' (Expected: 'Hello')\n", result12);
	free(result12);

	// Edge Case 5: Multiple strings with an empty separator
	char *strs13[] = {"A", "B", "C"};
	char *sep13 = "";
	char *result13 = ft_strjoin(3, strs13, sep13);
	printf("'%s' (Expected: 'ABC')\n", result13);
	free(result13);

	return (0);
} */
