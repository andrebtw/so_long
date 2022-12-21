/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:20:23 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/01 17:45:01 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr2(int n, int fd)
{
	int	remainder;

	if (n == -2147483648)
	{
		if (write(fd, "-2147483648", 11) == -1)
			return (-1);
		return (0);
	}
	if (n < 0)
	{
		if (write(fd, "-", 1) == -1)
			return (-1);
		n = -n;
	}
	if (n == 0)
		return (0);
	if (ft_putnbr2(n / 10, fd) == -1)
		return (-1);
	remainder = (n % 10) + '0';
	if (write(fd, &remainder, 1) == -1)
		return (-1);
	return (0);
}

int	ft_putnbr_fd_p(int n, int fd)
{
	if (n == 0)
	{
		n = n + '0';
		if (write(fd, &n, 1) == -1)
			return (-1);
		return (0);
	}
	if (ft_putnbr2(n, fd) == -1)
		return (-1);
	return (0);
}

static int	ft_putnbr_u_2(unsigned int n, int fd)
{
	int	remainder;

	if (n == 0)
		return (0);
	if (ft_putnbr2(n / 10, fd) == -1)
		return (-1);
	remainder = (n % 10) + '0';
	if (write(fd, &remainder, 1) == -1)
		return (-1);
	return (0);
}

int	ft_putnbr_u_fd(unsigned int n, int fd)
{
	if (n == 0)
	{
		n = n + '0';
		if (write(fd, &n, 1) == -1)
			return (-1);
		return (0);
	}
	if (ft_putnbr_u_2(n, fd) == -1)
		return (-1);
	return (0);
}
