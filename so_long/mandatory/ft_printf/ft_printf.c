/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:15:44 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/21 15:23:51 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_format(va_list args, char c)
{
	int	counter;

	counter = 0;
	if (c == '%')
		counter += ft_putchar_fd_p('%', 1);
	else if (c == 'd' || c == 'i')
		counter += ft_putnbr_fd_p(va_arg(args, int), 1);
	else if (c == 'c')
		counter += ft_putchar_fd_p(va_arg(args, int), 1);
	else if (c == 's')
		counter += ft_putstr_fd_p(va_arg(args, char *), 1);
	else if (c == 'p')
		counter += ft_puthex_p(va_arg(args, unsigned long long), c);
	else if (c == 'x' || c == 'X')
		counter += ft_puthex_p(va_arg(args, unsigned int), c);
	else if (c == 'u')
		counter += ft_putunint_fd_p(va_arg(args, unsigned int), 1);
	else
		return (0);
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	int		counter;
	va_list	args;

	va_start(args, str);
	counter = 0;
	if (write (1, "", 0) == -1)
		return (-1);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			counter += ft_format(args, *(str + 1));
			str++;
		}
		else
			counter += ft_putchar_fd_p(*str, 1);
		str++;
	}
	va_end(args);
	return (counter);
}
