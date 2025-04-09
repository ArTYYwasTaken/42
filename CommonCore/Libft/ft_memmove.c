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

void *ft_memmove(void *dest, const void *src, size_t n)
{
    // Check for NULL pointers to avoid undefined behavior
    if (!dest || !src)
        return NULL;

    size_t i;
    unsigned char *dp;
    const unsigned char *sp;

    // Cast the destination and source pointers to unsigned char pointers
    dp = (unsigned char *)dest;
    sp = (const unsigned char *)src;

    // Check if the destination overlaps with the source and is after it
    if (dp > sp && dp < sp + n)
    {
        // If overlapping, copy backwards to prevent overwriting source data
        i = n;
        while (i--)
        {
            dp[i] = sp[i];
        }
    } else
    {
        // If no overlap or destination is before source, copy forwards
        i = 0;
        while (i < n)
        {
            dp[i] = sp[i];
            i++;
        }
    }
    // Return the destination pointer
    return (dest);
}