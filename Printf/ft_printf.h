/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:37:41 by kemontei          #+#    #+#             */
/*   Updated: 2025/05/01 20:42:16 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

// Conversion functions
int     ft_printf(const char *str, ...);
int     ft_printchar(char c);
int     ft_printstring(const char *str);
int     ft_printfdecimal(int num);
int     printfunsigned(unsigned int num);
int     ft_printfhexadecimal(unsigned int num, char c);
int     ft_printfpointer(void *ptr);

// Helper functions
char	*ft_uitoa(unsigned int n);
char	*ft_itoa_base(unsigned int num, char *base);
char    *ft_luitoa_base(unsigned long int num, char *base);

#endif