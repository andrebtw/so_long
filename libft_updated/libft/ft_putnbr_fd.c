/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:28:54 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/09 18:32:46 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr2(int n, int fd)
{
	int	remainder;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n == 0)
		return ;
	ft_putnbr2(n / 10, fd);
	remainder = (n % 10) + '0';
	write(fd, &remainder, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		n = n + '0';
		write(fd, &n, 1);
	}
	else
		ft_putnbr2(n, fd);
}
