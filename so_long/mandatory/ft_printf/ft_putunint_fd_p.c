/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunint_fd_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:47:42 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/28 20:28:57 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numsize(unsigned int num)
{
	int	count;

	count = (num == 0);
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	ft_putunint_fd_p(unsigned int nb, int fd)
{
	unsigned int	n;

	n = nb;
	if (n > 9)
	{
		ft_putunint_fd_p(n / 10, fd);
		ft_putunint_fd_p(n % 10, fd);
	}
	else
		ft_putchar_fd_p(n + '0', fd);
	return (ft_numsize(nb));
}

// #include <stdio.h>
// int main()
// {
// 	int n = ft_putunint_fd_p(524525252, 1);
// 	printf("\n%d\n", n);
// }
