/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:28:25 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/28 20:28:28 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_p(unsigned long long num, char c)
{
	int		len;
	char	*hex_low;
	char	*hex_upp;

	hex_low = "0123456789abcdef";
	hex_upp = "0123456789ABCDEF";
	len = 0;
	if (c == 'p')
	{
		len += ft_putchar_fd_p('0', 1);
		len += ft_putchar_fd_p('x', 1);
		len += ft_puthex_p(num, 'x');
	}
	if (num >= 16 && c != 'p')
		len += ft_puthex_p(num / 16, c);
	if (c == 'x')
		len += ft_putchar_fd_p(hex_low[num % 16], 1);
	else if (c == 'X')
		len += ft_putchar_fd_p(hex_upp[num % 16], 1);
	return (len);
}
