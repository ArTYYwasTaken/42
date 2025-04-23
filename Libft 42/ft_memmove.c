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
    - dest: Pointer to the destination memory area.
    - src: Pointer to the source memory area.
    - n: Number of bytes to copy.

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
	{
		i = 0;
		while (i < n)
		{
			dp[i] = sp[i];
			i++;
		}
	}
	return (dest);
}
/*
// TEST CODE
void print_memory(const char *label, const unsigned char *mem, size_t n) {
    printf("%s: ", label);
    for (size_t i = 0; i < n; i++) {
        printf("%02x ", mem[i]);
    }
    printf("\n");
}

void test_memmove(const char *test_name, unsigned char *dest1,
	unsigned char *dest2, const unsigned char *src, size_t n) {
    printf("Test: %s\n", test_name);

    // Use the standard memmove
    memmove(dest1, src, n);
    // Use the custom ft_memmove
    ft_memmove(dest2, src, n);

    // Print memory content for comparison
    print_memory("Standard memmove", dest1, n);
    print_memory("Custom ft_memmove", dest2, n);

    // Compare results
    if (memcmp(dest1, dest2, n) == 0) {
        printf("Result: PASS\n\n");
    } else {
        printf("Result: FAIL\n\n");
    }
}

int main() {
    // Test case 1: Non-overlapping regions
    unsigned char src1[] = "Hello, World!";
    unsigned char dest1[20] = {0};
    unsigned char dest2[20] = {0};
    test_memmove("Non-overlapping regions", dest1, dest2, src1, 13);

    // Test case 2: Overlapping regions (dest before src)
    unsigned char src2[] = "Hello, World!";
    test_memmove("Overlapping regions (dest before src)", src2 + 7, src2 + 7,
	src2, 6);

    // Test case 3: Overlapping regions (src before dest)
    unsigned char src3[] = "Hello, World!";
    test_memmove("Overlapping regions (src before dest)", src3, src3,
	src3 + 7, 6);
    return 0;
}
*/
