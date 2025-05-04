/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfdecimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:08:29 by kemontei          #+#    #+#             */
/*   Updated: 2025/05/01 20:47:09 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	ft_printfdecimal(int num)
{
	int		total;
	char	*str;

	total = 0;
	str = ft_itoa(num);
	total = write(1, str, ft_strlen(str));
	free (str);
	return (total);
}
