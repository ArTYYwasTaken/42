/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:39:46 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:39:46 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION:
    Copies 'n' bytes from memory area 'src' to memory area 'dest'.
    The memory areas may overlap; copying is done in a non-destructive manner.

    PARAMETERS:
    - void *dest: Pointer to the destination memory area.
    - const void *src: Pointer to the source memory area.
    - size_t n: Number of bytes to copy.

    RETURN VALUE:
    Returns a pointer to the destination memory area 'dest'.
*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dp;
	const unsigned char	*sp;

	if (!n)
		return (dest);
	dp = (unsigned char *)dest;
	sp = (const unsigned char *)src;
	if (dp > sp && dp < sp + n)
	{
		i = n;
		while (i--)
			dp[i] = sp[i];
	}
	else
		ft_memcpy(dp, sp, n);
	return (dest);
}
/*
int main()
{
	char str1[] = "ABCDEF";
	char str2[] = "ABCDEF";

	printf("%s\n",(char *)memmove(str1 + 2, str1, 4));
	printf("%s\n", (char *)ft_memmove(str2 + 2, str2, 4));
}
*/