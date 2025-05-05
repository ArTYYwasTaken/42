/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfdecimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:08:29 by kemontei          #+#    #+#             */
/*   Updated: 2025/05/05 15:38:06 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	ft_printfdecimal(int num)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_itoa(num);
	count = write(1, str, ft_strlen(str));
	free (str);
	return (count);
}
