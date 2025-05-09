/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbento-c <dbento-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:49:48 by dbento-c          #+#    #+#             */
/*   Updated: 2025/03/14 00:04:55 by dbento-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/*int main(void) {
    int x = 5;
    int y = 4;
    printf("antes da troca x = %d, y = %d\n", x, y);

    ft_swap(&x, &y);

    printf("depois da troca x = %d, y = %d\n", x, y);
return 0;
}*/
