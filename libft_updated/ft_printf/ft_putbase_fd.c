/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:27:31 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/01 17:47:33 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_recursive_base(unsigned long n, int fd, char *base)
{
	unsigned long long	remainder;
	unsigned long long	base_size;

	if (n == 0)
		return (0);
	base_size = ft_strlen_p(base);
	if (ft_recursive_base(n / base_size, fd, base) == -1)
		return (-1);
	remainder = (n % base_size);
	if (write(fd, &base[remainder], 1) == -1)
		return (-1);
	return (0);
}

int	ft_putbase_fd_p(unsigned long n, int fd, char *base)
{
	if (!n)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
	}
	else
	{
		if (ft_recursive_base(n, fd, base) == -1)
			return (-1);
	}
	return (0);
}

int	ft_recursive_base_int(unsigned int n, int fd, char *base)
{
	unsigned int	remainder;
	unsigned int	base_size;

	if (n == 0)
		return (0);
	base_size = ft_strlen_p(base);
	if (ft_recursive_base_int(n / base_size, fd, base) == -1)
		return (-1);
	remainder = (n % base_size);
	if (write(fd, &base[remainder], 1) == -1)
		return (-1);
	return (0);
}

int	ft_putbase_int_fd(unsigned int n, int fd, char *base)
{
	if (!n)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (0);
	}
	if (ft_recursive_base(n, fd, base) == -1)
		return (-1);
	return (0);
}
