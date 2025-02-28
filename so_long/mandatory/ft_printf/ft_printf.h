/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:06:30 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/21 15:23:51 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putstr_fd_p(char *s, int fd);
int	ft_putchar_fd_p(char c, int fd);
int	ft_putnbr_fd_p(int n, int fd);
int	ft_puthex_p(unsigned long long num, char c);
int	ft_putunint_fd_p(unsigned int nb, int fd);

#endif
