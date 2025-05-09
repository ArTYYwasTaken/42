/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfunsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:07:22 by kemontei          #+#    #+#             */
/*   Updated: 2025/05/05 17:08:54 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	printfunsigned(unsigned int num)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_uitoa(num);
	if (!str)
		return (-1);
	count = write(1, str, ft_strlen(str));
	free (str);
	return (count);
}
