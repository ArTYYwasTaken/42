/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfunsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:07:22 by marvin            #+#    #+#             */
/*   Updated: 2025/05/03 19:07:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int printfunsigned(unsigned int num)
{
	int		total;
	char	*str;

	total = 0;
	str = ft_uitoa(num);
	if (!str)
		return (0);
	total = write(1, str, ft_strlen(str));
	free (str);
	return (total);
}
