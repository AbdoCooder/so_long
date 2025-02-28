/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:28:38 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/28 20:28:41 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numsize(int num)
{
	int	count;

	count = (num <= 0);
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	ft_putnbr_fd_p(int nb, int fd)
{
	int	n;

	n = nb;
	if (n == -2147483648)
	{
		ft_putstr_fd_p("-2147483648", fd);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar_fd_p('-', fd);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd_p(n / 10, fd);
		ft_putnbr_fd_p(n % 10, fd);
	}
	else
	{
		ft_putchar_fd_p(n + '0', fd);
	}
	return (ft_numsize(nb));
}
// #include <stdio.h>
// int main()
// {
// 	int n = ft_putnbr_fd_p(45, 1);
// 	printf("\n%d\n", n);
// }
