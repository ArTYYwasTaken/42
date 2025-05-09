/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbento-c <dbento-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 22:53:39 by dbento-c          #+#    #+#             */
/*   Updated: 2025/03/14 00:25:27 by dbento-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	printf("%s", str);
}
/*int main(void)
{
    char *mens = "Boas!\n";
    ft_putstr(mens);
    return 0;
}*/
