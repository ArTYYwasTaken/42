/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfhexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:13:47 by marvin            #+#    #+#             */
/*   Updated: 2025/05/03 19:13:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int ft_printfhexadecimal(unsigned int num, char c)
{
	int		total;
	char	*str;

	total = 0;
	if (c == 'x')
		str = ft_itoa_base(num, "0123456789abcdef");
	else if (c == 'X')
		str = ft_itoa_base(num, "0123456789ABCDEF");
	if (!str)
		return (-1);
	total = write(1, str, ft_strlen(str));
	free (str);
	return (total);
}
